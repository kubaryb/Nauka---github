#pragma once
#ifndef WEKTOR2D_H
#define WEKTOR2D_H

template <class typ>
class wektor<typ*>
{
protected:
	int dlg;
	int* dlg_w;
	typ** wart;
public:
	wektor(const std::initializer_list<typ>&);
	virtual ~wektor();
	virtual void print() const;
};

template <class typ>
wektor<typ*>::wektor(const std::initializer_list<typ> &x)
{
	dlg = x.size();
	wart = new typ*[dlg];
	dlg_w = new typ[dlg];
	int it = 0;
	for (auto el : x)
	{
		dlg_w[it] = el.size();
		wart[it] = new typ[dlg_w[it]];
		int i = 0;
		for (auto el2 : el)
		{
			wart[it][i] = el2;
			++i;
		}
		++it;
	}
}

template <class typ>
wektor<typ*>::~wektor()
{
	for (int i = 0;i < dlg;++i)
		delete[]wart[i];
	delete[]wart;
}

template <class typ>
void wektor<typ*>::print() const
{
	for (int i = 0;i < dlg;++i)
	{
		for (int j = 0;j<dlg_w[i];++j)
			std::cout << wart[i][j] << " ";
		std::cout << "\n";
	}
	std::cout << "\n";
}

#endif // !WEKTOR2D_H
