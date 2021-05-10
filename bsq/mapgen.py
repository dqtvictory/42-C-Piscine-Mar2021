"""
PROGRAM TO GENERATE A RANDOM MAP OF CUSTOM SIZE FOR THE BSQ PROJECT AT SCHOOL 42
"""


import random


### GLOBALS ###

EMPTY	= '.'
OBS		= 'o'
FILLED	= 'x'


### FUNCTIONS ##

def blue(text: str) -> str:
    beg = '\033[94m'
    end = '\033[0m'
    return f"{beg}{text}{end}"

def red(text: str) -> str:
    beg = '\033[91m'
    end = '\033[0m'
    return f"{beg}{text}{end}"

def green(text: str) -> str:
    beg = '\033[92m'
    end = '\033[0m'
    return f"{beg}{text}{end}"

def user_entry() -> tuple:
	nr = nc = no = 0

	while True:
		nr_str = input("Nombre de lignes: ")
		try:
			nr = int(nr_str)
			if nr > 0:
				break
		except:
			continue
		
	while True:
		nc_str = input("Nombre de colonnes: ")
		try:
			nc = int(nc_str)
		except:
			continue
		if nc > 0:
			break
	max_obs = (nr * nc) // 3

	while True:
		no_str = input(f"Nombre d'obstacles (max {max_obs}): ")
		try:
			no = int(no_str)
		except:
			continue
		if no <= max_obs:
			break
	return (nr, nc, no)

def put_obs(plan: list, num_obs: int):
	for _ in range(num_obs):
		while True:
			place = random.choice(range(len(plan)))
			if plan[place] == EMPTY:
				plan[place] = OBS
				break

def print_map(plan: list, nr: int, nc: int):
	for i, sq in enumerate(plan):
		print(red(sq), end='')
		if i % nc == nc - 1:
			print()

def ask_to_save() -> str:
	print("Sauvegarder tableau ? Entrer le nom du fichier à sauvegarder, ou laisser vide pour abandonner, puis taper Enter")
	return input("Nom du fichier : ")

def write_file(fname: str, plan: list, nr: int, nc: int):
	with open(fname, 'w') as f:
		f.write(f"{nr}{EMPTY}{OBS}{FILLED}\n")
		for i, sq in enumerate(plan):
			f.write(sq)
			if i % nc == nc - 1:
				f.write('\n')


### PROGRAM ###

if (__name__ == '__main__'):
	nr, nc, no = user_entry()
	plan = [EMPTY for _ in range(nr * nc)]
	put_obs(plan, no)
	
	print("\nTableau généré :")
	print(red(f"{nr}{EMPTY}{OBS}{FILLED}"))
	print_map(plan, nr, nc)
	
	fname = ask_to_save()
	if fname:
		write_file(fname, plan, nr, nc)