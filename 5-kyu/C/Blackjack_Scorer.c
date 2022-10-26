/* Complete the function that determines the score of a hand in the card game Blackjack (aka 21).

The function receives an array of strings that represent each card in 
the hand ("2", "3", ..., "10", "J", "Q", "K" or "A") and should return the score of the hand (integer).

Note: in C the function receives a character array with the card 10 represented by the character T.

Scoring rules:

Number cards count as their face value (2 through 10). 
Jack, Queen and King count as 10. An Ace can be counted as either 1 or 11.

Return the highest score of the cards that is less than or equal to 21. 
If there is no score less than or equal to 21 return the smallest score more than 21.

Examples

["A"]                           ==>  11
["A", "J"]                      ==>  21
["A", "10", "A"]                ==>  12
["5", "3", "7"]                 ==>  15
["5", "4", "3", "2", "A", "K"]  ==>  25 */

#include <stddef.h>

int score_hand(size_t n, const char cards[n]) 
{
  int score = 0, n_a = 0;
  for (size_t i = 0; i < n; i++)
  {
    if (cards[i] >= '0' && cards[i] <= '9')
      score += cards[i] - '0';
    else if (cards[i] == 'J' || cards[i] == 'Q' || cards[i] == 'K' || cards[i] == 'T')
      score += 10;
    else if (cards[i] == 'A')
      n_a++;
  }
  for (size_t i = 0; i < n; i++)
  {
    if (cards[i] == 'A')
    {
      if (score < 10 && n_a > 1)
        score += 11;
      else if (score > 10 || n_a > 1)
        score += 1;
      else
        score += 11;
    }
  }
  return score;
}
