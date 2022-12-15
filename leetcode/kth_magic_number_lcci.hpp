#ifndef EASYCPP_KTH_MAGIC_NUMBER_LCCI_HPP
#define EASYCPP_KTH_MAGIC_NUMBER_LCCI_HPP
#include <vector>
using namespace std;
namespace lc {
class kthMagicNumberSolution {
public:
  int getKthMagicNumber(int k) {
    vector<int> dp(k+1);
    dp[1] = 1;
    int p3 = 1, p5 = 1, p7 = 1;
    for (int i = 2; i <= k; i++) {
      int num3 = dp[p3] * 3, num5 = dp[p5] * 5, num7 = dp[p7] * 7;
      dp[i] = min(num3, min(num5, num7));
      if (dp[i] == num3) {
        p3++;
      }
      if (dp[i] == num5) {
        p5++;
      }
      if (dp[i] == num7) {
        p7++;
      }
    }
    return dp[k];
  }
};
}
#endif //EASYCPP_KTH_MAGIC_NUMBER_LCCI_HPP
