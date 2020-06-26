#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <string>
using namespace std;



class PCC {
private:
	
	void create(double price, double width, double hight, double weight, int id) {
		this->price = price;
		this->width = width;
		this->hight = hight;
		this->weight = weight;
		this->id = id;
	}


public:
	double price, width, hight, weight;
	int id;
	void set_price(double x) {
		price = x;
	}
	
	void set_width(double x) {
		width = x;
	}
	
	void set_hight(double x) {
		hight = x;
	}
	
	void set_weight(double x) {
		weight = x;
	}
	
	void set_id(double x) {
		id = x;
	}
	PCC & operator ++() {
		this->id += 1;
		this->price += 1;
		return *this;
	}
	PCC & operator ++(int) {
		PCC temp(*this);
		this->id += 1;
		this->price += 1;
		return temp;
	}
	PCC & operator --() {
		this->id += 1;
		this->price += 1;
		return *this;
	}
	PCC & operator --(int) {
		PCC temp(*this);
		this->id += 1;
		this->price += 1;
		return temp;
	}
	PCC(int id) {
		srand(time(0));
		int a = rand() % 100;
		create(a, a, a, a, id);
	}
	PCC(double price, double width, double hight, double weight, int id) {
		create(price, width, hight, weight, id);
	}
	PCC() {
		srand(time(0));
		int a = rand() % 100;
		create(a, a, a, a, 0);
	}
	void output() {
		cout << this->price << " " << this->width << " " << this->hight << " " << this->weight << " " << this->id << " ";
	}
	double get_price() {
		return price;
	}

	double get_weight() {
		return weight;
	}
	double get_hight() {
		return hight;
	}
	double get_width() {
		return width;
	}
	int get_id() {
		return id;
	}
};
class chip : public PCC {
private:
	
	void create(double price, double width, double hight, double weight, int id, string log_elements) {
		this->price = price;
		this->width = width;
		this->hight = hight;
		this->weight = weight;
		this->id = id;
		this->log_elements = log_elements;
	}
public:
	string log_elements;
	string get_log_elements() {
		return log_elements;
	}
	void set_log_elements(string x) {
		log_elements = x;
	}
};

class chipset : public chip {
private:
	
	void create(double price, double width, double hight, double weight, int id, string log_elements, string proizvoditel) {
		this->price = price;
		this->width = width;
		this->hight = hight;
		this->weight = weight;
		this->id = id;
		this->log_elements = log_elements;
		this->proizvoditel = proizvoditel;
	}
public: 
	string proizvoditel;
	string get_proizvoditel() {
		return proizvoditel;
	}
	void set_proizvoditel(string x) {
		proizvoditel = x;
	}
	
};

class graphics_proc : public chip {
private:
	void create(double price, double width, double hight, double weight, int id, string log_elements, string proizvoditel) {
		this->price = price;
		this->width = width;
		this->hight = hight;
		this->weight = weight;
		this->id = id;
		this->log_elements = log_elements;
		this->proizvoditel = proizvoditel;
	}
public:
	string proizvoditel;
	string get_proizvoditel() {
		return proizvoditel;
	}
	void set_proizvoditel(string x) {
		proizvoditel = x;
	}
};

class main_proc : public graphics_proc {
private:
	void create(double price, double width, double hight, double weight, int id, string log_elements, string proizvoditel,string takt) {
		this->price = price;
		this->width = width;
		this->hight = hight;
		this->weight = weight;
		this->id = id;
		this->log_elements = log_elements;
		this->proizvoditel = proizvoditel;
		this->takt = takt;
	}
public:
	string takt;
	string get_takt() {
		return takt;
	}
	void set_takt(string x) {
		takt = x;
	}
}; 

class motherboard : public chipset {
private:
	void create(double price, double width, double hight, double weight, int id, string log_elements, string proizvoditel, string form_factor) {
		this->price = price;
		this->width = width;
		this->hight = hight;
		this->weight = weight;
		this->id = id;
		this->log_elements = log_elements;
		this->proizvoditel = proizvoditel;
		this->form_factor = form_factor;
	}
public:
	string form_factor;
	string get_form_factor() {
		return form_factor;
	}
	void set_form_factor(string x) {
		form_factor = x;
	}
};

class graphics_card : public chipset {
private:
	
	void create(double price, double width, double hight, double weight, int id, string log_elements, string proizvoditel,int V_memory) {
	this->price = price;
	this->width = width;
	this->hight = hight;
	this->weight = weight;
	this->id = id;
	this->log_elements = log_elements;
	this->proizvoditel = proizvoditel;
	this->V_memory = V_memory;
}
public: int V_memory;
		int get_V_memory() {
			return V_memory;
		}
		void set_V_memory(int x) {
			 V_memory=x;
		}		
		
};









	class kub {
	private:
		int a;
		PCC ***p;
		void create(int a) {
			this->a = a;
			int x;
			p = new PCC **[a];
			for (int i = 0; i < a; i++)
			{
				p[i] = new PCC *[a];
				for (int j = 0; j < a; j++)
					p[i][j] = new PCC[a];
			}
		}
		void del()
		{
			delete p;
		}
	public:
		kub(int a) {
			create(a);
		}
		~kub() {
			del();
		}
		void write(int x, int y, int z, PCC *h);
		void read(int x, int y, int z, PCC*h);
		void sort_weight();
		void search_id(int id);
		void output_weight();
};


void kub::write(int x, int y, int z, PCC *h)
{
	p[x][y][z] = *h;
}

void kub::read(int x, int y, int z, PCC *g)
{
	*g = p[x][y][z];
}

void kub::sort_weight()
{
	int e = 0;
	int size = a;
	int q = size * size*size;
	PCC *r = new PCC[q];
	for (int x = 0; x < size; x++)
		for (int y = 0; y < size; y++)
			for (int z = 0; z < size; z++) {
				PCC o = p[x][y][z];
				r[e] = o;
				e++;
			}
	for (int i = 0; i < q - 1; i++)
	{
		for (int j = 0; j < q - 1 - i; j++)
		{
			if (r[j].get_weight() > r[j + 1].get_weight()) {
				PCC t = r[j];
				r[j] = r[j + 1];
				r[j + 1] = t;
			}

		}

	}
	e = 0;
	for (int x = 0; x < size; x++)
		for (int y = 0; y < size; y++)
			for (int z = 0; z < size; z++) {
				PCC o = r[e];
				p[x][y][z] = o;
				e++;
			}
}

void kub::search_id(int id)
{
	int t = a;
	bool r = false;
	for (int x = 0; x < t; x++)
		for (int y = 0; y < t; y++)
			for (int z = 0; z < t; z++)
			{
				PCC q = this->p[x][y][z];
				int i = q.get_id();
				if (i == id) {
					r = true;
					q.output();
				}
			}
	if (!r)cout << " данные не найдены";
	cout << endl;
}

void kub::output_weight()
{

	for (int x = 0; x < a; x++)
		for (int y = 0; y < a; y++)
			for (int z = 0; z < a; z++) {
				PCC o = p[x][y][z];
				cout << o.get_weight() << " ";
			}
	cout << endl;
}






int main()
{
	setlocale(LC_ALL, "rus");
	kub q = 2;
	int e;
	bool s = true;
	PCC a(1, 2, 3, 4, 5);
	PCC a1(5, 6, 7, 8, 9);
	PCC a2(5, 6, 7, 7, 9);
	PCC a3(2);
	PCC a4(2);
	PCC a5 = 6;
	PCC a6(5, 6, 7, 2, 9);
	PCC a7(5, 6, 7, 1, 9);
	a++;
	++a1;
	--a2;
	a3--;
	while (s) {
		cin >> e;
		switch (e) {
		case 1:

			q.write(0, 0, 0, &a);
			q.write(0, 0, 1, &a1);
			q.write(0, 1, 0, &a2);
			q.write(0, 1, 1, &a3);
			q.write(1, 0, 0, &a4);
			q.write(1, 0, 1, &a5);
			q.write(1, 1, 0, &a6);
			q.write(1, 1, 1, &a7);
			break;
		case 2:

			q.search_id(1);
			break;
		case 3:
			q.output_weight();
			q.sort_weight();
			q.output_weight();
			break;
		default:
			s = false;
			break;
		}

	}
	system("pause");
	return 0;
}
