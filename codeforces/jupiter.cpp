#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
class profit{
        int n, total_cpu, total_gpu, total_customer;
        vector<int> profit, cpu, gpu, ans;
    public:
        void profit_from_product(){
            n = 5;
            profit.resize(n);
            for(int i = 1; i < n; i++){
                cin >> profit[i];
            }
            cin >> total_customer;
        }
        void cpu_gpu_cost(){
            cpu.resize(n);
            gpu.resize(n);
            for(int i = 1; i < n; i++){
                cin >> cpu[i] >> gpu[i];
            }
            cin >> total_cpu >> total_gpu;
        }
        vector<int> find_max_profit(){
            int x1, x2, x3, x4, maxx = 0, tc1, tc2, tc3, tc4, tg1, tg2, tg3, tg4;
            ans.resize(n-1);
            for(x1 = 0; x1 <= total_customer; x1++){
                tc1 = total_cpu - x1*cpu[1];
                tg1 = total_gpu - x1*gpu[1];
                if(tc1 >= 0 && tg1 >= 0){ 
                    for(x2 = 0; x1+x2 <= total_customer; x2++){
                        tc2 = tc1 - x2*cpu[2];
                        tg2 = tg1 - x2*gpu[2];
                        if(tc2 >= 0 && tg2 >= 0){ 
                            for(x3 = 0; x1+x2+x3 <= total_customer; x3++){
                                tc3 = tc2 - x3*cpu[3];
                                tg3 = tg2 - x3*gpu[3];
                                if(tc3 >= 0 && tg3 >= 0){
                                    int s = 0, e = total_customer;
                                    while(s <= e){ 
                                        x4 = (s+e)/2;
                                        tc4 = tc3 - x4*cpu[4];
                                        tg4 = tg3 - x4*gpu[4];
                                        if(x1+x2+x3+x4 <= total_customer && tc4 >= 0 && tg4 >= 0){
                                                int max_profit_yet = x1*profit[1] + x2*profit[2] + x3*profit[3] + x4*profit[4];
                                                if(maxx < max_profit_yet){
                                                    maxx = max_profit_yet;
                                                    ans = {x1, x2, x3, x4};
                                                }   
                                                s = x4+1;
                                        }   
                                        else{
                                            e = x4-1;
                                        }   
                                    }   
                                }   
                            }   
                        }   
                    }   
                }   
            }   
            return ans;
        }   
};
int main(){
    profit rs;
    rs.profit_from_product();
    rs.cpu_gpu_cost();
    vector<int> ans = rs.find_max_profit();
    cout << "Maximum Profit can be earned by selling " << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << "Product " << i+1 << " to " << ans[i] << " customers" << endl;
    }
    return 0;
}

