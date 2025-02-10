#include <iostream>
#include <vector>
#include <cmath>

int main() {
    // 假设 r_req, V_req, V_att 是已知的向量
    std::vector<double> r_req = { /* 填充数据 */ };
    std::vector<std::vector<double>> V_req = { /* 填充数据 */ };
    std::vector<double> V_att = { /* 填充数据 */ };

    double p0 = /* 填充数据 */;
    double req = /* 填充数据 */;
    double r_att = /* 填充数据 */;
    std::vector<double> P_req(r_req.size(), 0.0);

    for (size_t k = 0; k < r_req.size(); ++k) {
        if (r_req[k] <= p0) {
            double P_req1 = req * (1.0 / r_req[k] - 1.0 / p0) * std::pow(r_att, 2) / std::pow(r_req[k], 2);
            double P_req2 = req * std::pow(1.0 / r_req[k] - 1.0 / p0, 2) * r_att;

            std::vector<double> P_reqk(2, 0.0); // 假设 P_reqk 是二维向量
            P_reqk[0] = P_req1 / r_req[k] * V_req[k][0] + P_req2 / r_att * V_att[0];
            P_reqk[1] = P_req1 / r_req[k] * V_req[k][1] + P_req2 / r_att * V_att[1];

            // 累加到 P_req
            P_req[k] += P_reqk[0] + P_reqk[1];
        }
    }

    return 0;
}