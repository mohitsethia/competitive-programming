        vector<int> find_max_profit(){
            int x1, x2, x3, x4, tg = g, maxx = 0, tc1, tc2, tc3, tc4, tg1, tg2, tg3, tg4;
            v.resize(n);
            for(x1 = 0; x1 <= t; x1++){
                tc1 = c - x1*cpu[0];
                tg1 = g - x1*gpu[0];
                if(tc1 >= 0 && tg1 >= 0){ 
                    for(x2 = 0; x1+x2 <= t; x2++){
                        tc2 = tc1 - x2*cpu[1];
                        tg2 = tg1 - x2*gpu[1];
                        if(tc2 >= 0 && tg2 >= 0){ 
                            for(x3 = 0; x1+x2+x3 <= t; x3++){
                                tc3 = tc2 - x3*cpu[2];
                                tg3 = tg2 - x3*gpu[2];
                                if(tc3 >= 0 && tg3 >= 0){ 
                                    int s4 = 0, e4 = 50; 
                                    while(s <= e){ 
                                        x4 = (s+e)/2;
                                        tc4 = tc3 - x4*cpu[3];
                                        tg4 = tg3 - x4*gpu[3];
                                        if(x1+x2+x3+x4 <= 50 && tc4 >= 0 && tg4 >= 0){ 
                                                int max_profit_yet = x1*p[0] + x2*p[1] + x3*p[2] + x4*p[3];
                                                if(maxx < max_profit_yet){
                                                    maxx = max_profit_yet;
                                                    v = {x1, x2, x3, x4};
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
            return v;
        }   

