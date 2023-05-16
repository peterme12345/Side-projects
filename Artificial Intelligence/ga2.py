import random
import numpy
import board
import time


def selection(states, obj):
    rating = []
    acc = 0
    for state in states:
        rating.append(1/obj[acc].get_fitness())
        if len(states) < len(obj):
            acc += 1

    total = sum(rating)
    prob = [field/total for field in rating]
    select = random.choices(states, prob, k=2)

    return select


def crossover(states):

    p1 = states[0]

    p2 = states[1]

    c1 = p1[:3] + \
        p2[3:5] + \
        p1[5:]

    c2 = p2[:3] + \
        p1[3:5] + \
        p2[5:]

    return [c1, c2]


def mutation(states):
    mutated = []
    for state in states:
        for x in range(len(state)):
            if random.random() < .1:
                new_value = random.randint(0, 7)
                state = state[:x] + str(new_value) + state[x+1:]
        mutated.append(state)
    return mutated


def main():
    start = time.time()
    states = []
    obj = []

    for i in range(8):
        field = board.Board(8)
        obj.append(field)
        initial = ""
        for row in range(field.n_queen):
            for col in range(field.n_queen):
                if field.map[row][col] == 1:
                    initial += str(col)
        states.append(initial)

    best_fitness = 8
    best_solution = None

    while best_fitness > 0:
        for i in range(100):
            pair = selection(states, obj)
            new_pair = crossover(pair)
            mutate = mutation(new_pair)
            states = states + mutate

            for state in states:
                new = state
                new_field = board.Board(8)
                for row in range(8):
                    for col in range(8):
                        if new[col] == 1:
                            new_field[row][col] == 1
                fitness = new_field.get_fitness()
                best_fitness = fitness
                best_solution = new_field
                if fitness < best_fitness:
                    best_fitness = fitness
                    best_solution = new_field

                if best_fitness == 0:
                    print("Solution found:")
                    best_solution.show_map()
                    break

            if best_fitness == 0:
                break

            states = states[:8]

        print(best_fitness)
        best_solution.show_map()

    end = time.time()
    print("Running time: {} ms".format(
        round((end - start) * 1000)))


main()
