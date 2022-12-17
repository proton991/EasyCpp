#ifndef EASYCPP_PMS_HPP
#define EASYCPP_PMS_HPP
#include <string>
using namespace std;

const int MaxSize = 1000;

struct ProductInfo {
  int productID;
  string productTitle;
  float productPrice;
};

struct ProductList {
  int last{0};
  ProductInfo products[MaxSize];
};

struct ProductNode {
  ProductInfo data;
  struct ProductNode* next;
};

// use sequential list
class ProductManagementSys {
public:
  ProductManagementSys() {
    NO_SUCH_PRODUCT.productID = 0x3f3f3f;
    NO_SUCH_PRODUCT.productTitle = "INVALID_PRODUCT";
    NO_SUCH_PRODUCT.productPrice = -1.0f;
  }

  bool AddProduct(const ProductInfo& info) {
    if (m_productList.last >= MaxSize) {
      return false;
    }
    m_productList.products[m_productList.last++] = info;
    return true;
  }

  int NumProducts() const {
    return m_productList.last;
  }

  ProductInfo QueryByID(int id) {
    for (int i = 0; i < m_productList.last; i++) {
      if (m_productList.products[i].productID == id) {
        return m_productList.products[i];
      }
    }
    return NO_SUCH_PRODUCT;
  }

  bool DeleteByID(int id) {
    int index = -1;
    for (int i = 0; i < m_productList.last; i++) {
      if (m_productList.products[i].productID == id) {
        index = i;
      }
    }
    if (index == -1) {
      return false;
    }
    if (index == m_productList.last - 1) {
      m_productList.last--;
      return true;
    }
    for (int i = index; i < m_productList.last; i++) {
      m_productList.products[i] = m_productList.products[i+1];
    }
    m_productList.last--;
    return true;
  }
private:
  ProductList m_productList;
  ProductInfo NO_SUCH_PRODUCT;
};

#endif  //EASYCPP_PMS_HPP
