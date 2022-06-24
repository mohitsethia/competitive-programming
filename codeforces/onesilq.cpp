#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Card {
    string cardColor;
    vector<pair<string, int>> cardPrice;
    public:
    void setPrice(vector<pair<string, int>> token, string color) {
        cardPrice = token;
        cardColor = color;
    }
    vector<pair<string, int>> getPrice() {
        return cardPrice;
    }
    string getCardColor() {
        return cardColor;
    }
};

bool canBuy(Card card, map<string, int> &tokens, map<string, int> &discount) {
    // 5 kinds of tokens
    // any kind can be present in card
    for(pair<string, int> purchase: card.getPrice()) {
        if(tokens[purchase.first]+discount[purchase.first] < purchase.second) {
            return false;
        }
    }
    return true;
}

map<string, int> calculateCards(map<int, pair<vector<Card>, map<string, int>>> &users, int userId) {
    map<string, int> canTakeDiscount;
    for(auto card: users[userId].first) {
        canTakeDiscount[card.getCardColor()]++;
    }
    return canTakeDiscount;
}

void buyCard(Card card, map<int, pair<vector<Card>, map<string, int>>> &users, int userId) {
    map<string, int> discount = calculateCards(users, userId);
    if(canBuy(card, users[userId].second, discount)) {
        users[userId].first.push_back(card);
        for(pair<string, int> pur: card.getPrice()) {
            if(discount[pur.first] >= pur.second) {
                continue;
            }
            users[userId].second[pur.first] -= (pur.second - discount[pur.first]);
        }
    }
}


void printCard(map<int, pair<vector<Card>, map<string, int>>> &users) {
    for(auto allTokens: users[1].second) {
        cout << allTokens.first << " " << allTokens.second << "\n";
    }
}

int main() {
    int n = 3;
    vector<Card> cards;
    Card obj;
    vector<pair<string, int>> token;
    token.push_back({"white", 4});
    token.push_back({"red", 2});
    obj.setPrice(token, "black");
    cards.push_back(obj);
    map<int, pair<vector<Card>, map<string, int>>> users;
    map<string, int> userToken;
    userToken["white"] = 5;
    userToken["red"] = 7;
    userToken["black"] = 3;
    users[1] = make_pair(vector<Card>(), userToken);
        buyCard(cards[0], users, 1);
        printCard(users);
    token.clear();
    token.push_back({"black", 4});
    token.push_back({"red", 3});
    obj.setPrice(token, "white");
    cards.push_back(obj);
    buyCard(cards[1], users, 1);
    printCard(users);
}
