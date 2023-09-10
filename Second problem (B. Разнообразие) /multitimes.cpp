#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <map>
using namespace std;

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    multiset <int> cardsA, cardsB;
    map <int,int> CardA, CardB;
    for (int i=0; i<N; ++i) {
            int card;
            cin >> card;
            cardsA.insert(card);
            CardA[card]++;
    }
    for (int i=0; i<M; ++i) {
            int card;
            cin >> card;
            cardsB.insert(card);
            CardB[card]++;
    }
    multiset <int> res, res1;
    set_difference(cardsA.begin(), cardsA.end(), cardsB.begin(), cardsB.end(), inserter(res, res.begin()));
    set_difference(cardsB.begin(), cardsB.end(), cardsA.begin(), cardsA.end(), inserter(res1, res1.begin()));
    unordered_multiset <int> cardsA1, cardsB1;
    cardsA1.insert(cardsA.begin(), cardsA.end());
    cardsB1.insert(cardsB.begin(), cardsB.end());
    int res_k = res.size() + res1.size();
    for (int i=0; i<Q; ++i) {
            char player;
            int card, type;
            cin >> type >> player >> card;
            if (player=='A')
            {
                if (type == 1)
                {
                    CardA[card]++;
                    if(CardA[card]>CardB[card]) res_k++;
                    else res_k--;
                }
                else
                {
                    CardA[card]--;
                    if(CardA[card]>=CardB[card]) res_k--;
                    else res_k++;
                }

            }
            else
            {
                if (type == 1)
                {
                    CardB[card]++;
                    if(CardB[card]>CardA[card]) res_k++;
                    else res_k--;
                }
                else
                {
                    CardB[card]--;
                    if(CardB[card]>=CardA[card]) res_k--;
                    else res_k++;
                }
            }
            //cout << cardsA.count(card) << ' ' << cardsB.count(card) << ' ';
            cout << res_k << " \n";
    }
}
