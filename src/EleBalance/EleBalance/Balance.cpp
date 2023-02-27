#include "Balance.h"


Balance::Balance() {
	
}

Balance::Balance(std::string a) {
	eq = a;
}

void Balance::Divide() {
	NumOfChemical = 1;
	for (char c : eq) {
		if (c == '=' || c == '+') NumOfChemical++;
	}
	int e = eq.find('=');
	left = eq.substr(0, e);
	right = eq.substr(e + 1);
	//std::cout << NumOfChemical << std::endl;
}

HashTable Balance::make_the_table(std::string str) {

	str.push_back('+');

	HashTable Ht;
	MakeStackChar st;
	MakeStackInt st_n;
	
	for (char c : str) {
		
		if (c != '+') {
			st.Push(c);
		}
		else {
			char mid[2] = { 0 };
			char a = 0;
			int n = 1;
			
			st_n.Push(n);
			while (st.StackSize() != 0) {
				a = st.Top();
				mid[0] = 0;
				mid[1] = 0;
				if (a <= 'z' && a >= 'a') {
					mid[1] = a;
					st.Pop();
					mid[0] = st.Top();
					Ht[mid] += n;
					//if (flag == 0) n = '1';
				}
				else if (a <= 'Z' && a >= 'A') {
					mid[0] = a;
					Ht[mid] += n;
					//if (flag == 0) n = '1';
				}
				else if (a <= '9' && a >= '0') {
					int t = 0;
					n = 0;
					while (a <= '9' && a >= '0') {
						n += (int)(a - '0') * (int)pow(10, t);
						st.Pop();
						a = st.Top();
						t++;
					}
					n *= st_n.Top();
					continue;
				}
				else if (a == ')') {
					st_n.Push(n * st_n.Top());
				}
				else if (a == '(') {
					st_n.Pop();
				}
				st.Pop();
				n = st_n.Top();
			}
		}
	}
	//Ht.HashCheck();
	//std::cout << Ht.HashSzie() << std::endl;
	return Ht;
}

std::string Balance::IntToString(int n) {
	std::string s;
	std::string ans;
	while (n > 0) {
		s.push_back((char)n % 10 + '0');
		n /= 10;
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		ans.push_back(s[i]);
	}
	return ans;
}

int Balance::gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int Balance::deter_value(int** mt, int s, int n) {
	int ans = 1;
	for (int i = 0; i < n; i++)
		ans *= mt[i][i];
	return ans * s;
}

void Balance::swap(int* a, int* b, int n) {
	int mid = 0;
	for (int i = 0; i < n; i++) {
		mid = a[i];
		a[i] = b[i];
		b[i] = mid;
	}
}

int Balance::determinant_change(int h, int l, int** mt) {
	int signal = 1;
	int l_ = l - 1;

	if (h == l) l_ = h;

	for (int i = 0; i < l_; i++) {
		for (int j = i + 1; j < h; j++) {
			while (mt[i][i]) {
				int c = mt[j][i] / mt[i][i];
				for (int k = i; k < l; k++) {
					mt[j][k] -= c * mt[i][k];
				}
				swap(mt[i], mt[j], l);
				signal = -signal;
			}
			swap(mt[i], mt[j], l);
			signal = -signal;

			
		}
	}
	return signal;
}

int Balance::Compare() {
	//std::cout << left << " " << right << std::endl;
	le = make_the_table(left);
	ri = make_the_table(right);
	//std::cout << le.HashSzie() << " " << ri.HashSzie() << std::endl;
	if (le.HashSzie() != ri.HashSzie()) return 0;
	for (int i = 0; i < le.HashSzie(); i++) {
		if (!ri.ElementSearch(le[i].ele)) return 0;
	}
	return 1;
}

std::string Balance::BlanceEquation() {
	if (abs(NumOfChemical - le.HashSzie()) >= 2)return "ERROR";
	std::string s = eq;
	s.push_back('+');
	std::string ans;
	std::string mid;
	EleMatrix M(NumOfChemical);
	int flag = 0;

	for (int i = 0; i < s.size();i++) {
		if (s[i] == '=' || s[i] == '+') {

			if (s[i] == '=')place = flag + 1;
			
			M[flag].ele = s.substr(0, i);
			M[flag].Ht = make_the_table(M[flag].ele);
			//M[flag].Ht.HashCheck();
			s = s.substr(i + 1);
			i = 0;
			flag++;
			
		}
	}

	int signal = 1, size = le.HashSzie();
	int** matrix;
	matrix = new int* [size];
	//std::cout << size << std::endl;

	for (int i = 0; i < size; i++) {
		matrix[i] = new int[NumOfChemical];
		
		for (int j = 0; j < NumOfChemical; j++) {
			if (j >= place && j < NumOfChemical - 1) signal = -1;
			else signal = 1;
			if (M[j].Ht.ElementSearch(le[i].ele) != 0) matrix[i][j] = signal * M[j].Ht.ElementSearch(le[i].ele);
			else matrix[i][j] = 0;
		}
	}


	/*
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < NumOfChemical; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << le[i].ele << std::endl;
	}
	for (int i = 0; i < NumOfChemical; i++) {
		std::cout << M[i].ele << " ";
	}
	std::cout << std::endl;
	*/

	int sg = determinant_change(size, NumOfChemical, matrix);

	int min_value;

	if ((NumOfChemical - 1) < size)min_value = NumOfChemical - 1;
	else min_value = size;
	//std::cout << min_value << ' ' << NumOfChemical << ' ' << size << std::endl;

	int D = deter_value(matrix, sg, min_value);
	//std::cout << D << std::endl;
	int* Dn = new int[min_value + 1];
	

	for (int i = 0; i < min_value; i++) {
		int** mid_matrix = new int* [min_value];
		for (int j = 0; j < min_value; j++) {
			mid_matrix[j] = new int[min_value];
			for (int k = 0; k < min_value; k++) {
				if (i == k)mid_matrix[j][k] = matrix[j][min_value];
				else mid_matrix[j][k] = matrix[j][k];
			}			
		}
		sg = determinant_change(min_value, min_value, mid_matrix);
		Dn[i] = deter_value(mid_matrix, sg, min_value);
		delete[] mid_matrix;

	}
	Dn[min_value] = D;

	int Gcd = Dn[0];
	for (int i = 0; i <= min_value; i++) {
		Gcd = gcd(Gcd, Dn[i]);
	}

	if (Gcd == 0) return "ERROR";
	for (int i = 0; i <= min_value; i++) {
		Dn[i] /= Gcd;
		
	}
	
	ans.clear();
	
	for (int i = 0; i < NumOfChemical; i++) {
		if (Dn[i] > 1) {
			ans = ans + IntToString(Dn[i]);
			ans.push_back(' ');
		}
		ans = ans + M[i].ele;
		//ans.push_back(' ');
		if (i == place - 1)ans += " = ";
		else if (i != NumOfChemical - 1)ans += " + ";

	}

	return ans;

}

void Balance::ElementCheck() {
	le.HashCheck();
}	