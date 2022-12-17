#include "pms.hpp"
#include <iostream>
// driver program
int main(int argc, char** argv) {
  ProductManagementSys pms;
  ProductInfo product1{};
  product1.productPrice = 200.0f;
  product1.productTitle = "PC";
  product1.productID = 0;
  pms.AddProduct(product1);
  std::cout << pms.QueryByID(0).productTitle << "\n";
  pms.DeleteByID(0);
  std::cout << pms.QueryByID(0).productTitle << "\n";
}