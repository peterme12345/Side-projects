import time
import numpy
import board


def hill(field):

    start = time.time()

    field.show_map()

    while True:

        if field.get_fitness() == 0:
            field.show_map()
            end = time.time()
            print("Running time: {} ms".format(
                round((end - start) * 1000)))
            break

        current = field.get_fitness()
        best = field

        for row in range(field.n_queen):
            for col in range(field.n_queen):
                if field.map[row][col] == 1:
                    for k in range(0, field.n_queen):
                        new = board.Board(field.n_queen)
                        for x in range(field.n_queen):
                            for y in range(field.n_queen):
                                if field.map[x][y] == 1:
                                    new.map[x][y] = 1
                        new.flip(row, col)
                        new.flip((row + k) % field.n_queen, col)
                        new_fitness = new.get_fitness()
                        if new_fitness < current:
                            continue
                        elif new_fitness > best.get_fitness():
                            best = new

        if best == field:
            field = board.Board(field.n_queen)
        else:
            field = best


test = board.Board(5)
hill(test)
