#include <iostream>
#include "Product.h"

using namespace std;

Product::Product()
{
	/* method */
	ProducePart();

	cout << "return a product" << endl;
}

Product::~Product() {}

void Product::ProducePart()
{
	cout << "build part of product" << endl;
}

ProductPart::ProductPart() {}
ProductPart::~ProductPart() {}

ProductPart* ProductPart::BuildPart()
{
	return new ProductPart;
}
