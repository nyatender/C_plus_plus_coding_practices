#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;

class DebtLedger {
public:
    // debts[from][to] = amount; from owes 'amount' to to
    unordered_map<string, unordered_map<string, double>> debts;

    // Add: from_user owes to_user amount
    void Add(const string& from_user, const string& to_user, double amount) {
        if (!debts.contains(from_user)) {
            debts.insert({ from_user, unordered_map<string, double>() });
        }
        if (!debts[from_user].contains(to_user)) {
            debts[from_user].insert({ to_user, 0.0 });
        }
        debts[from_user][to_user] += amount;
    }

    // Split: paid_by paid 'total' for split_among
    void Split(const string& paid_by, const vector<string>& split_among, double total_amount) {
        double share = total_amount / split_among.size();
        for (const auto& user : split_among) {
            if (user != paid_by) {
                Add(user, paid_by, share);
            }
        }
    }

    // Settle: from_user pays back some/all to to_user
    void Settle(const string& from_user, const string& to_user, double amount) {
        if (debts[from_user].count(to_user)) {
            debts[from_user][to_user] -= amount;
            if (debts[from_user][to_user] <= 0.0) 
                debts[from_user].erase(to_user);
            if (debts[from_user].empty()) 
                debts.erase(from_user);
        }
    }

    // SimplifyDebt: minimize number of transactions
    vector<tuple<string, string, double>> SimplifyDebt() {
        unordered_map<string, double> balance;

        // Build net balances
        for (const auto& from : debts) {
            for (const auto& to : from.second) {
                balance[from.first] -= to.second;
                balance[to.first] += to.second;
            }
        }
        // Track debtors/creditors
        vector<pair<string, double>> debtors, creditors;
        for (const auto& b : balance) {
            if (b.second < 0) 
                debtors.emplace_back(b.first, -b.second);
            else if (b.second > 0) 
                creditors.emplace_back(b.first, b.second);
        }
        // Greedily settle debts
        size_t i = 0, j = 0;
        vector<tuple<string, string, double>> result;
        while (i < debtors.size() && j < creditors.size()) {
            double to_settle = min(debtors[i].second, creditors[j].second);
            result.push_back({ debtors[i].first, creditors[j].first, to_settle });
            debtors[i].second -= to_settle;
            creditors[j].second -= to_settle;
            if (debtors[i].second == 0)
                ++i;
            if (creditors[j].second == 0) 
                ++j;
        }
        return result;
    }
};

class DebtLedgerDemo {

private:
    unordered_map<string, unordered_map<string, double>> debts;
    vector<tuple<string, string, double>> results;

public:
    void add(string from_user, string to_user, double amount) {
        if (!debts.contains(from_user)) {
            debts.insert({ from_user, unordered_map<string, double>() });
        }
        if (!debts[from_user].contains(to_user)) {
            debts[from_user].insert({to_user, 0.0});
        }
        debts[from_user][to_user] += amount;
    }

    // assuming: friends include paid by user
    void split(double amount, vector<string> friends, string paidBy) {
        double share = amount / friends.size();
        for (auto& user : friends) {
            if (0 == user.compare(paidBy)) {
                add(user, paidBy, share);
            }
        }
    }
    /*
    *  f1 -> f2 - amount
    *     -> f3 - amount
    *     -> f4 - amount
    * 
    *  f2 -> f1 - amount
    *     -> f3 - amount
    *     -> f4 - amount
    */
    vector<tuple<string, string, double>> simplyfySplits() {
        unordered_map<string, double> balance;

        // simplyfy transactions
        for (auto& from : debts) {
            for (auto& to : from.second) {
                if (!balance.contains(to.first)) {
                    balance.insert({ to.first, 0.0 });
                }
                balance[to.first] += to.second;
                if (!balance.contains(from.first)) {
                    balance.insert({ from.first, 0.0 });
                }
                balance[from.first] -= to.second;
            }
        }

        vector<pair<string, double>> debitors;
        vector<pair<string, double>> creditors;
       // unordered_map<string, double> creditors;

        // debitors and creditors
        for (auto& user : balance) {
            if (user.second < 0.0) {
                debitors.push_back({ user.first, -user.second });
            }
            else if(user.second > 0.0) {
                creditors.push_back({ user.first, user.second });
            }
        }

        int i = 0;
        int j = 0;
        while (i < debitors.size() && j < creditors.size()) {
            double minSettleAmouont = min(debitors[i].second, creditors[j].second);
            results.push_back({ debitors[i].first, creditors[j].first, minSettleAmouont });
            debitors[i].second -= minSettleAmouont;
            creditors[j].second -= minSettleAmouont;
            if (debitors[i].second == 0.0)
                i++;
            if (creditors[j].second == 0.0)
                j++;
        }

        return results;
    }
};


int main() {

    // test case 1
    //=====================================================
    //DebtLedger ledger;
    //ledger.Add("A", "B", 20); // A owes B 20
    //ledger.Add("B", "C", 40); // B owes C 40
    //ledger.Add("C", "A", 20); // C owes A 20



    //auto simplified = ledger.SimplifyDebt();
    //for (auto [from, to, amount] : simplified) {
    //    cout << from << " owes " << to << " -> $" << amount << endl;
    //}
    //=====================================================



    // test case 2
    //=====================================================

    DebtLedger ledgerObj;
    vector<string> friends = { "A", "B", "C", "D" };
    ledgerObj.Split("B", friends, 100);
    ledgerObj.Split("C", friends, 200);
    ledgerObj.Split("D", friends, 50);

    /*
        A -> Not paid anything
        B ->  100
        C ->  200
        D ->   60

        Split ->

        A-> B -> 25
            C -> 50
            D -> 15

        B-> C -> 50
            D -> 15

        C-> B -> 25
            D -> 15

        D-> B -> 25
            C -> 50
    */

    //ledgerObj.Settle("B", "D", 20);

    auto simplified = ledgerObj.SimplifyDebt();
    for (auto [from, to, amount] : simplified) {
        cout << from << " owes " << to << " -> $" << amount << endl;
    }

    //=====================================================

    return 0;
}