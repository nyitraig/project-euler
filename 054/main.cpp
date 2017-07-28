/* Problem 54
 * In the card game poker, a hand consists of five cards and are ranked,
 * from lowest to highest, in the following way:
 *     High Card: Highest value card.
 *     One Pair: Two cards of the same value.
 *     Two Pairs: Two different pairs.
 *     Three of a Kind: Three cards of the same value.
 *     Straight: All cards are consecutive values.
 *     Flush: All cards of the same suit.
 *     Full House: Three of a kind and a pair.
 *     Four of a Kind: Four cards of the same value.
 *     Straight Flush: All cards are consecutive values of same suit.
 *     Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
 * The cards are valued in the order:
 *        2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.
 * If two players have the same ranked hands
 * then the rank made up of the highest value wins;
 * But if two ranks tie, for example, both players have a pair of queens,
 * then highest cards in each hand are compared;
 * if the highest cards tie then the next highest cards are compared, and so on.
 * The file, poker.txt, contains one-thousand random hands dealt to two players.
 * Each line of the file contains ten cards (separated by a single space):
 * the first five are Player 1's cards and the last five are Player 2's cards.
 * You can assume that all hands are valid (no invalid characters or repeated cards),
 * each player's hand is in no specific order, and in each hand there is a clear winner.
 * How many hands does Player 1 win?
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

enum Suit  { SPADES, HEARTS, DIAMONDS, CLUBS};
enum Value { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
enum Rank  { HIGHCARD, ONEPAIR, TWOPAIRS, THREEOFAKIND, STRAIGHT, FLUSH,
             FULLHOUSE, FOUROFAKIND, STRAIGHTFLUSH, ROYALFLUSH};

class Card {
private:
	Suit  _s;
	Value _v;
public:
	Suit  s () const { return _s; }
	Value v () const { return _v; }
	bool operator< (const Card& c) const { return _v < c._v; }
	friend std::istream& operator>> (std::istream& is, Card& c) {
		char s, v;
		is >> s >> v;
		switch (v) {
			case 'S' : c._s = Suit::SPADES;   break;
			case 'H' : c._s = Suit::HEARTS;   break;
			case 'D' : c._s = Suit::DIAMONDS; break;
			case 'C' : c._s = Suit::CLUBS;    break;
			default  : is.setstate(std::ios::failbit); break;
		}
		switch (s) {
			case '2' : c._v = Value::TWO;   break;
			case '3' : c._v = Value::THREE; break;
			case '4' : c._v = Value::FOUR;  break;
			case '5' : c._v = Value::FIVE;  break;
			case '6' : c._v = Value::SIX;   break;
			case '7' : c._v = Value::SEVEN; break;
			case '8' : c._v = Value::EIGHT; break;
			case '9' : c._v = Value::NINE;  break;
			case 'T' : c._v = Value::TEN;   break;
			case 'J' : c._v = Value::JACK;  break;
			case 'Q' : c._v = Value::QUEEN; break;
			case 'K' : c._v = Value::KING;  break;
			case 'A' : c._v = Value::ACE;   break;
			default  : is.setstate(std::ios::failbit); break;
		}
		return is;
	}
};

void moveBack (std::vector<Card>& hand, const int& from, const int& to) {
	std::vector<Card> newHand;
	for (int i = 0; i < hand.size(); i++)
		if (i < from || i > to)
			newHand.push_back(hand[i]);
	for (int i = 0; i < hand.size(); i++)
		if (i >= from && i <= to)
			newHand.push_back(hand[i]);
	hand.swap(newHand);
}

Rank handRank (std::vector<Card>& hand) {
	Rank r = Rank::HIGHCARD;
	std::sort(hand.begin(), hand.end());
	if (hand[0].v() == hand[1].v() || hand[1].v() == hand[2].v() ||
	    hand[2].v() == hand[3].v() || hand[3].v() == hand[4].v())
		r = Rank::ONEPAIR;
	if ((hand[0].v() == hand[1].v() && hand[2].v() == hand[3].v()) ||
	    (hand[0].v() == hand[1].v() && hand[3].v() == hand[4].v()) ||
		(hand[1].v() == hand[2].v() && hand[3].v() == hand[4].v()))
		r = Rank::TWOPAIRS;
	if (hand[0].v() == hand[2].v() || hand[1].v() == hand[3].v() ||
	    hand[2].v() == hand[4].v())
		r = Rank::THREEOFAKIND;
	if (hand[0].v() + 1 == hand[1].v() && hand[1].v() + 1 == hand[2].v() &&
	    hand[2].v() + 1 == hand[3].v() && hand[3].v() + 1 == hand[4].v())
		r = Rank::STRAIGHT;
	if (hand[0].s() == hand[1].s() && hand[1].s() == hand[2].s() &&
	    hand[2].s() == hand[3].s() && hand[3].s() == hand[4].s())
		r = (r == Rank::STRAIGHT) ? Rank::STRAIGHTFLUSH : Rank::FLUSH;
	if ((hand[0].v() == hand[2].v() && hand[3].v() == hand[4].v()) ||
	    (hand[0].v() == hand[1].v() && hand[2].v() == hand[4].v()))
		r = Rank::FULLHOUSE;
	if (hand[0].v() == hand[3].v() || hand[1].v() == hand[4].v())
		r = Rank::FOUROFAKIND;
	if (r == Rank::STRAIGHTFLUSH && hand[4].v() == Value::ACE)
		r = Rank::ROYALFLUSH;
	// rearrange hand in order to easier determine winner in case of a tie
	for (int i = 0; i < 3; i++)
		if (r == Rank::ONEPAIR && hand[i].v() == hand[i + 1].v())
			moveBack(hand, i, i + 1);
	if (r == Rank::TWOPAIRS && hand[1].v() != hand[2].v() && hand[2].v() != hand[3].v())
		moveBack(hand, 2, 2);
	if (r == Rank::THREEOFAKIND && hand[1].v() == hand[3].v())
		moveBack(hand, 1, 3);
	if ((r == Rank::FOUROFAKIND && hand[0].v() == hand[3].v()) ||
	    (r == Rank::TWOPAIRS && hand[3].v() != hand[4].v()))
		moveBack(hand, 0, 3);
	if ((r == Rank::FULLHOUSE && hand[0].v() == hand[2].v()) ||
	    (r == Rank::THREEOFAKIND && hand[0].v() == hand[2].v()))
		moveBack(hand, 0, 2);
	return r;
}

int main () {
	unsigned int n = 0;
	std::ifstream ifs("./054/p054_poker.txt", std::ifstream::binary);
	if (!ifs.is_open()) {
		std::cout << "Can't open file";
		return 1;
	}
	while (ifs.good()) {
		std::vector<Card> player1, player2;
		player1.resize(5); player2.resize(5);
		for (int i = 0; i < 5; i++)
			ifs >> player1[i];
		for (int i = 0; i < 5; i++)
			ifs >> player2[i];
		Rank p1Rank = handRank(player1), p2Rank = handRank(player2);
		if (p1Rank > p2Rank)
			n++;
		if (p1Rank == p2Rank)
			for (int i = 4; i >= 0; i--) {
				if (player1[i].v() < player2[i].v())
					break;
				if (player1[i].v() > player2[i].v()) {
					n++; break;
				}
			}
	}
	ifs.close();
	std::cout << n;
	return 0;
}
