# DESCRIPTION:
# Write a function named first_non_repeating_letter that takes a string input, 
# and returns the first character that is not repeated anywhere in the string.

# For example, if given the input 'stress', the function should return 't', 
# since the letter t only occurs once in the string, and occurs first in the string.

# As an added challenge, upper- and lowercase letters are considered the same character, 
# but the function should return the correct case for the initial letter. For example, the input 'sTreSS' should return 'T'.

# If a string contains all repeating characters, it should return an empty string ("") or None.

def first_non_repeating_letter(string):
    s2 = string.lower()
    i = 0
    for c in s2:
        if s2.find(c, s2.find(c) + 1) < 0:
            return string[i]
        i += 1
    return ''