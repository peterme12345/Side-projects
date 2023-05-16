import sys
import math


class City:  # constructor for city's latitude/longitude
    def __init__(self, name, latitude, longitude):
        self.name = name
        self.latitude = latitude
        self.longitude = longitude


class Map:  # constructor for distance between cities
    def __init__(self, name, dist):
        self.name = name
        self.dist = dist


c1 = sys.argv[1]
c2 = sys.argv[2]

cities = [0]
route = ['Best route: ']
setofLists = []
visited = []
prevlist = []
total = []


def parseCoords(c1):
    cities.pop()
    file = open("coordinates.txt")
    read = file.readlines()
    parsed_cities = []
    nums = []
    acc = 0
    for e in read:
        parsed_cities.append(e.strip())
    for c in parsed_cities:
        if c[:parsed_cities[acc].find(':')] == c1:
            acc = acc
            break
        else:
            acc += 1

    for l in parsed_cities[acc]:
        if l.isdigit() == True or l == '.' or l == ',' or l == '-':
            nums.append(l)

    for x in range(len(nums)-1):
        nums[0] += nums[x+1]

    while len(nums) != 1:
        nums.pop()

    cities.append(City(parsed_cities[acc][0:parsed_cities[acc].find(':')], float(
        nums[0][0:nums[0].find(',')]), float(nums[0][nums[0].find(',')+1:])))

    file.close()
    return cities[0]


def straight_line(a, b):
    l1 = (a.latitude*math.pi)/180
    l2 = (b.latitude*math.pi)/180
    a1 = (a.longitude*math.pi)/180
    a2 = (b.longitude*math.pi)/180

    straight = 2*3958.8*math.asin((math.sqrt(math.sin((l2-l1)/2)**2 + math.cos(l1)
                                             * math.cos(l2)*math.sin((a2-a1)/2)**2)))
    return straight


def parsemaps(a):
    file = open("map.txt")
    read = file.readlines()

    nearbycities = []
    distance = []

    for e in read:
        distance.append(e.strip())

    acc = 0
    for d in distance:
        if d[:distance[acc].find('-')] == a:
            acc = acc
            break
        else:
            acc += 1

    distance[acc].split(',')
    distance[acc] = distance[acc][distance[acc].find('-')+1:]

    w = distance[acc]

    list = w.split(',')

    for x in range(len(list)):
        s = 5
        while list[0][list[0].find('(')+1:w.find(')')+s].find(')') > 0:
            s -= 1
            a = list[0][list[0].find('(')+1:w.find(')')+s]

        nearbycities.append(Map(list[0][:list[0].find('(')],
                                float(a)))

        list.pop(0)
    file.close()
    return nearbycities


def distofCity(list):
    name = list[0].name
    min = list[0].dist
    for o in list:
        if o.dist < min:
            min = o.dist
            name = o.name
    city = Map(name, min)
    return city
    # sortedbyDist = sorted(list, key=lambda x: x.dist)


def calc(l):
    name = l[0].name
    min = l[0].dist+straight_line(parseCoords(l[0].name), parseCoords(c2))
    for o in l:
        if o.dist + straight_line(parseCoords(o.name), parseCoords(c2)) < min:
            min = o.dist + straight_line(parseCoords(o.name), parseCoords(c2))
            name = o.name
    city = Map(name, min)
    return city


"""
def calcH(c):
    # list = []
    # for n in parsemaps(first.name):
    c.dist = straight_line(parseCoords(
        c.name), parseCoords(c2)) + c.dist
    # list.append(n)
    # setofLists.append(list)
    # prevlist = list
    return c.dist

"""


def main():
    output = ('From city:', c1, '\nTo city:', c2)
    print(' '.join(output))

    first = parseCoords(c1)
    visited.append(first.name)
    route.append(first.name)
    route.append('->')

    list = parsemaps(first.name)
    prevName = first.name
    min = list[0].dist + \
        straight_line(parseCoords(list[0].name), parseCoords(c2))
    name = list[0].name
    prevValue = min

    for c in list:
        c.dist = c.dist+straight_line(parseCoords(c.name), parseCoords(c2))
        c.name = c.name
        if c.dist < min:
            min = c.dist
            name = c.name
    setofLists.append(list)
    newlist = []
    if min > prevValue:
        setofLists.pop()
        list = parsemaps(prevName)
        for c in list:
            newlist.append(c)
            if c == distofCity(list):
                pass
        name = calc(newlist).name

    total.append(min-straight_line(parseCoords(name), parseCoords(c2)))

# _____________________________________________________________
    prevName = name
    prevValue = min
    first = parseCoords(name)
    list = parsemaps(first.name)

    min = list[0].dist + \
        straight_line(parseCoords(list[0].name), parseCoords(c2))
    name = list[0].name

    for c in list:
        c.dist = c.dist+straight_line(parseCoords(c.name), parseCoords(c2))
        c.name = c.name
        if c.dist < min:
            min = c.dist
            name = c.name
    setofLists.append(list)
    newlist = []
    if min > prevValue:
        setofLists.pop()
        list = parsemaps(prevName)
        for c in list:
            newlist.append(c)
            if c == distofCity(list):
                pass
        name = calc(newlist).name

# ___________________   __________________________________________
    prevName = name
    prevValue = min
    first = parseCoords(name)
    list = parsemaps(first.name)

    min = list[0].dist + \
        straight_line(parseCoords(list[0].name), parseCoords(c2))
    name = list[0].name

    for c in list:
        c.dist = c.dist+straight_line(parseCoords(c.name), parseCoords(c2))
        c.name = c.name
        if c.dist < min:
            min = c.dist
            name = c.name
    setofLists.append(list)
    newlist = []
    if min > prevValue:
        setofLists.pop()
        list = parsemaps(prevName)
        for c in list:
            newlist.append(c)
            if c == distofCity(list):
                pass
        name = calc(newlist).name
# _____________________________________________________________
    prevName = name
    prevValue = min
    first = parseCoords(name)
    list = parsemaps(first.name)

    min = list[0].dist + \
        straight_line(parseCoords(list[0].name), parseCoords(c2))
    name = list[0].name
    index = 0
    for c in list:
        index += 1
        c.dist = c.dist+straight_line(parseCoords(c.name), parseCoords(c2))
        c.name = c.name
        if c.dist < min:
            min = c.dist
            name = c.name
            index = index
    setofLists.append(list)
    newlist = []
    if min > prevValue:
        setofLists.pop()
        list = parsemaps(prevName)
        for c in list:
            newlist.append(c)
            if c.name == distofCity(list).name:
                newlist.pop()

    # list = parsemaps(name)
    # list.index(calc(list))

    # for x in range(len(visited)):
    #    print(visited[x])
   # print(len(setofLists))


main()

# __________________________________________________-

# first = prevlist[0][0].name
# print(first)
# first = distofCity(prevlist)
# __________________________


##
# print(prevlist[0])

"""
 init = 0
    if len(setofLists) != 1:
        init = distofCity(
            list).dist
        for l in setofLists:
            if distofCity(l).dist+straight_line(parseCoords(distofCity(l).name), parseCoords(c2)) < init:
                init = l.dist + \
                    straight_line(parseCoords(l.name), parseCoords(c2))
"""
# print(' '.join(route))
# print('Total distance: ')


# print(list[0].dist)
# print(straight_line(parseCoords(first.name), parseCoords(c2))
# )
# min = dist + \
# straight_line(parseCoords(first.name), parseCoords(c2))

# for c in parsemaps(first.name):
#   temp = calcH(c)
#   if temp < min:
#      min = temp
# print(min.name)


"""
    route.append(c1)
    route.append('->')
    print(' '.join(route))
    print('Total distance: ')
    print(len(visited))
"""


"""
    for x in range(2):
        ways = parsemaps(first)
        closest = distofCity(ways)

        for y in range(len(setofLists)):
            prevways = distofCity(setofLists[y])
            if closest.dist <= prevways.dist and (closest.name not in visited):
                visited.append(closest.name)
                first = closest
                temp = first
            else:
                first = temp

            if c2 in visited:
                break
            possible = listofWays(first)

        route.append(visited[x])
        route.append('->')
    print(' '.join(route))
    print('Total distance: ')
    print(len(visited))

main()
"""


"""
    newlist2 = []

    for n in parsemaps(first.name):
        n.dist = straight_line(parseCoords(
            n.name), parseCoords(c2)) + n.dist
        newlist2.append(n)

    least.append(newlist2)
    last = distofCity(newlist2)

    for v in range(len(least)):
        prev = distofCity(least[v])

        if last.dist <= prev.dist and (last.name not in visited):
            visited.append(last.name)
            first = last
        else:
            first = prev

    newlist3 = []
    for n in parsemaps(first.name):
        n.dist = straight_line(parseCoords(
            n.name), parseCoords(c2)) + n.dist
        newlist3.append(n)

    least.append(newlist3)
    last = distofCity(newlist3)

    for v in range(len(least)):
        prev = distofCity(least[v])

        if last.dist <= prev.dist and (last.name not in visited):
            visited.append(last.name)
            first = last

"""

"""
    nlist = []
    for n in parsemaps(first.name):
        n.dist = straight_line(parseCoords(
            n.name), parseCoords(c2)) + n.dist
        nlist.append(n)

    least.append(nlist)
    last = distofCity(nlist)

    for v in range(len(least)):
        prev = distofCity(least[v])

        if last.dist <= prev.dist:
            visited.append(last.name)
            first = last
"""


"""
    last = distofCity(list)
    visited.append(distofCity(list))
    first = parseCoords(last)
    for n in range(1):
        list = []
        if first not in visited:
            visited.append(first.name)
            for n in parsemaps(first.name):
                n.dist = straight_line(parseCoords(
                    n.name), parseCoords(c2)) + n.dist
                list.append(n)

    least.append(list)
    flast = distofCity(list)
    visited.append(distofCity(list))
    # for x in range(len(list)):
    # print(list[x].name)
"""

# for y in range(len(least)):
# for x in range(len(least[y])):
#    print(least[0][x].dist)


# list.append(cost)
"""
            if dist < cost:
                cost = dist

            print()
"""


"""
            for c in parsemaps(temp):
                acc = 0

                if c not in visited:
                    near = closestcity(c)
                    dist = near[acc].dist + \
                        straight_line(near[acc], parseCoords(c2))
                    if dist < cost:
                        cost = dist

                acc += 1
            """


"""
    while target != sys.argv[2]:
        temp = closestcity(target)
        target = closestcity(temp)
        print(target)
    print(target)
"""


"""
parsed_cities = []
for e in read:
    parsed_cities.append(e.strip())

nums = []
cities = []
acc = 0

for c in parsed_cities:
    if c[:parsed_cities[acc].find(':')] == sys.argv[1]:
        acc = acc
        break
    else:
        acc += 1

for l in parsed_cities[acc]:
    if l.isdigit() == True or l == '.' or l == ',' or l == '-':
        nums.append(l)

for x in range(len(nums)-1):
    nums[0] += nums[x+1]


while len(nums) != 1:
    nums.pop()

cities.append(City(parsed_cities[acc][0:parsed_cities[acc].find(':')], float(
    nums[0][0:nums[0].find(',')]), float(nums[0][nums[0].find(',')+1:])))


nums.pop()
acc = 0
for c2 in parsed_cities:
    if c2[:parsed_cities[acc].find(':')] == sys.argv[2]:
        acc = acc
        break
    else:
        acc += 1

for l in parsed_cities[acc]:
    if l.isdigit() == True or l == '.' or l == ',' or l == '-':
        nums.append(l)

for x in range(len(nums)-1):
    nums[0] += nums[x+1]


while len(nums) != 1:
    nums.pop()

cities.append(City(parsed_cities[acc][0:parsed_cities[acc].find(':')], float(
    nums[0][0:nums[0].find(',')]), float(nums[0][nums[0].find(',')+1:])))

file.close()
s = ["From city:", sys.argv[1], "\nTo city:", sys.argv[2]]
print(' '.join(s))

l1 = (cities[0].latitude*math.pi)/180
l2 = (cities[1].latitude*math.pi)/180

a1 = (cities[0].longitude*math.pi)/180
a2 = (cities[0].longitude*math.pi)/180

straight = 2*3958.8*math.asin(math.sqrt(math.sin((l2-l1)/2)**2 + math.cos(l1)
                                        * math.cos(l2)*math.sin((a2-a1)/2)**2))

distance = []

file = open("map.txt")
read = file.readlines()

for e in read:
    distance.append(e.strip())

n = 0

for d in distance:
    if d[:distance[n].find('-')] == sys.argv[1]:
        n = n
        break
    else:
        n += 1

distance[n].split(',')
distance[n] = distance[n][distance[n].find('-')+1:]


maps = []

w = distance[n]


list = w.split(',')

for x in range(len(list)):
    s = 5
    while list[0][list[0].find('(')+1:w.find(')')+s].find(')') > 0:
        s -= 1
        a = list[0][list[0].find('(')+1:w.find(')')+s]

    maps.append(Map(list[0][:list[0].find('(')],
                    float(a)))

    list.pop(0)

ways = []

for x in range(len(maps)):
    maps[x].dist = straight + maps[x].dist

    short = min(maps)


route = ['Best route: ', sys.argv[1], ' - ', short.name]


print(' '.join(route))

h = 0

for r in distance:
    if r[:distance[h].find('-')] == short.name:
        n = n
        break
    else:
        n += 1

distance[h].split(',')
distance[h] = distance[h][distance[h].find('-')+1:]

maps2 = []

new = distance[h]

nlist = new.split(',')

for x in range(len(nlist)):
    s = 5
    while nlist[0][nlist[0].find('(')+1:new.find(')')+s].find(')') > 0:
        s -= 1
        b = nlist[0][nlist[0].find('(')+1:new.find(')')+s]

    maps2.append(Map(nlist[0][:nlist[0].find('(')],
                     float(b)))

    nlist.pop(0)
"""
