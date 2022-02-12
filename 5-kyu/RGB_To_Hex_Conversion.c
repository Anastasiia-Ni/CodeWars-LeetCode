/* The rgb function is incomplete. Complete it so that passing in 
RGB decimal values will result in a hexadecimal representation being returned. 
Valid decimal values for RGB are 0 - 255. Any values that fall out of that range 
must be rounded to the closest valid value.

Note: Your answer should always be 6 characters long, 
he shorthand with 3 will not work here. */

int check (int n)
{
  if (n < 0)
    return 0;
  if (n > 255)
    return 255;
  return n;
}

int rgb(int r, int g, int b, char *output)
{
  char *base = "0123456789ABCDEF";
  output[1] = base[check(r) % 16];
  output[0] = base[(check(r) / 16)];
  output[3] = base[check(g) % 16];
  output[2] = base[(check(g) / 16)];
  output[5] = base[check(b) % 16];
  output[4] = base[(check(b) / 16)];
  return 1; 
}
