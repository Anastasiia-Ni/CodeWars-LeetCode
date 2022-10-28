# In this kata you have to create all permutations of a non empty input string 
# and remove duplicates, if present. This means, you have to shuffle all letters 
# from the input in all possible orders.

# Examples:
# * With input 'a'
# * Your function should return: ['a']
# * With input 'ab'
# * Your function should return ['ab', 'ba']
# * With input 'aabb'
# * Your function should return ['aabb', 'abab', 'abba', 'baab', 'baba', 'bbaa']

# The order of the permutations doesn't matter.

def permutations(s):
    res = set([s])
    if len(s) == 2:
        res.add(s[1] + s[0])
    elif len(s) > 2:
        for i, j in enumerate(s):
            for n in permutations(s[:i] + s[i + 1:]):
                res.add(j + n)
    return list(res)