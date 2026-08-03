
#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void printDeck(CardDeck deck)
{
  int ind;
  for (ind = 0; ind < deck.size; ind ++)
    {
      printf("%c ", deck.cards[ind]);
    }
  printf("\n");
}


void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{
  for (int i = 0; i < origDeck.size - 1; i++) {
    leftDeck[i].size = i + 1;
    rightDeck[i].size = origDeck.size - (i + 1);

    memcpy(&leftDeck[i].cards, origDeck.cards, (i + 1) * sizeof(char));
    memcpy(&rightDeck[i].cards, origDeck.cards + (i +1), (origDeck.size - (i + 1)) * sizeof(char));

  }
}


  void helper(CardDeck leftDeck, CardDeck rightDeck, CardDeck *result, int left, int right, int out, int round) {
    if(left == leftDeck.size) {
      while(right < rightDeck.size) {
        result->cards[out] = rightDeck.cards[right];
        out++;
        right++;
      }
      if(round == 1) {
        printDeck(*result);
      }
      else {
        shuffle(*result, round - 1);
      }
      return;
    }

    if(right == rightDeck.size) {
      while(left < leftDeck.size) {
        result->cards[out] = leftDeck.cards[left];
        out++;
        left++;
      }
      if(round == 1) {
        printDeck(*result);
      }
      else {
        shuffle(*result, round - 1);
      }
      return;
    }
    else {
      result->cards[out] = leftDeck.cards[left];
      helper(leftDeck, rightDeck, result, (left+ 1), right, (out + 1), round);

      result->cards[out] = rightDeck.cards[right];
      helper(leftDeck, rightDeck, result, left, (right + 1), (out + 1), round);
    }
  }

void interleave(CardDeck leftDeck, CardDeck rightDeck, int round)
{
CardDeck result;
result.size = leftDeck.size + rightDeck.size;

int left = 0;
int right = 0;
int out = 0;

helper(leftDeck, rightDeck, &result, left, right, out, round);
}


void shuffle(CardDeck origDeck, int round)
{
  int numDecks = origDeck.size - 1;
  CardDeck *leftDeck = malloc(numDecks * sizeof(CardDeck));
  CardDeck *rightDeck = malloc(numDecks * sizeof(CardDeck));
    if (leftDeck == NULL || rightDeck == NULL) {
      free(leftDeck);
      free(rightDeck);
      return;
  }
  divide(origDeck, leftDeck, rightDeck);

  int i = 0;
  while(i < numDecks) {
  interleave(leftDeck[i], rightDeck[i], round);
  i++;
  }

  free(leftDeck);
  free(rightDeck);
}

