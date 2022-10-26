# Test examples:
# "EBG13 rknzcyr." -->
# "ROT13 example."

# "This is my first ROT13 excercise!" -->
# "Guvf vf zl svefg EBG13 rkprepvfr!"

def rot13(message):
    res = ""
    for c in message:
        if c.isalpha():
            if (c >= 'a' and c <= 'm') or (c >= 'A' and c <= 'M'):
                res += chr(ord(c) + 13)
            elif (c >= 'n' and c <= 'z') or (c >= 'N' and c <= 'Z'):
                res += chr(ord(c) - 13)
        else:
            res += c
    return res