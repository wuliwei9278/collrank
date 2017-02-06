#ifndef __ELEMENTS_HPP__
#define __ELEMENTS_HPP__

struct rating
{
	int user_id;
	int item_id;
	double score;

	rating(): user_id(0), item_id(0), score(0.) {}
	rating(int u, int i, double s): user_id(u), item_id(i), score(s) {}
	void setvalues(const int u, const int i, const double s) {
		user_id = u;
		item_id = i;
		score = s;
	}
	void swap(rating& r) {
		int temp;
		temp = user_id; user_id = r.user_id; r.user_id = temp;
		temp = item_id; item_id = r.item_id; r.item_id = temp;
    double tempf;
		tempf = score; score = r.score; r.score = tempf;
	}
};

struct comparison
{
	int user_id;
	int item1_id;
	int item2_id;
  int comp;

	comparison(): user_id(0), item1_id(0), item2_id(0), comp(1) {}
	comparison(int u, int i1, int i2, int cp): user_id(u), item1_id(i1), item2_id(i2), comp(cp) {}
	comparison(const comparison& c): user_id(c.user_id), item1_id(c.item1_id), item2_id(c.item2_id), comp(c.comp) {}
	void setvalues(const int u, const int i1, const int i2, const int cp) {
		user_id = u;
		item1_id = i1;
		item2_id = i2;
    comp = cp;
	}
	void swap(comparison& c) {
		int temp;
		temp = user_id; user_id = c.user_id; c.user_id = temp;
		temp = item1_id; item1_id = c.item1_id; c.item1_id = temp;
		temp = item2_id; item2_id = c.item2_id; c.item2_id = temp;
	  temp = comp; comp = c.comp; c.comp = temp;
  }
};

bool comp_userwise(comparison a, comparison b) { return ((a.user_id < b.user_id) || ((a.user_id == b.user_id) && (a.item1_id < b.item1_id))); }
bool comp_itemwise(comparison a, comparison b) { return ((a.item1_id < b.item1_id) || ((a.item1_id == b.item1_id) && (a.user_id < b.user_id))); }
bool rating_userwise(rating a, rating b) { return ((a.user_id < b.user_id) || ((a.user_id == b.user_id) && (a.item_id < b.item_id))); }
bool rating_scorewise(rating a, rating b) { return (a.score > b.score); }

typedef struct rating rating;
typedef struct comparison comparison;

#endif
