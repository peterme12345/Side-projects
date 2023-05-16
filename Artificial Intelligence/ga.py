import random

# Define the size of the chess board
board_size = 8

# Define the population size
population_size = 100

# Define the number of generations to run
generations = 500

# Define the mutation probability
mutation_probability = 0.1

# Generate the initial population


def generate_population(size):
    population = []
    for i in range(size):
        chromosome = [random.randint(1, board_size) for _ in range(board_size)]
        population.append(chromosome)
    return population

# Evaluate the fitness of each chromosome


def evaluate_fitness(chromosome):
    clashes = 0
    for i in range(len(chromosome)):
        for j in range(i+1, len(chromosome)):
            if chromosome[i] == chromosome[j]:
                clashes += 1
            if abs(chromosome[i] - chromosome[j]) == j - i:
                clashes += 1
    return 28 - clashes

# Select the parents using roulette wheel selection


def roulette_wheel_selection(population):
    fitness_sum = sum(evaluate_fitness(chromosome)
                      for chromosome in population)
    selection_probs = [evaluate_fitness(
        chromosome) / fitness_sum for chromosome in population]
    return random.choices(population, weights=selection_probs, k=2)

# Perform crossover using single-point crossover


def single_point_crossover(parents):
    crossover_point = random.randint(1, board_size-1)
    child1 = parents[0][:crossover_point] + parents[1][crossover_point:]
    child2 = parents[1][:crossover_point] + parents[0][crossover_point:]
    return child1, child2

# Perform mutation by swapping two genes


def swap_mutation(chromosome):
    if random.random() < mutation_probability:
        i = random.randint(0, board_size-1)
        j = random.randint(0, board_size-1)
        chromosome[i], chromosome[j] = chromosome[j], chromosome[i]
    return chromosome


# Run the genetic algorithm
population = generate_population(population_size)
for generation in range(generations):
    # Select parents
    parents = roulette_wheel_selection(population)

    # Perform crossover
    children = single_point_crossover(parents)

    # Perform mutation
    mutated_children = [swap_mutation(child) for child in children]

    # Replace worst chromosomes with mutated children
    population.sort(key=evaluate_fitness)
    population[-2:] = mutated_children

    # Print the best chromosome for this generation
    population.sort(key=evaluate_fitness, reverse=True)
    print(
        f"Generation {generation+1}: Best chromosome = {population[0]}, Fitness = {evaluate_fitness(population[0])}")

# Print the final solution
print(f"Final solution: {population[0]}")
