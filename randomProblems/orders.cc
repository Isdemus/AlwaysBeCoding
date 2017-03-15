#include <set>
#include <vector>
#include <unordered_map>

#include <iostream>

using namespace std;

typedef struct Order {
	string ordername;
} Order;

typedef struct OrderDep {
	Order order;
	Order orderDep;
} OrderDep;

int PlaceOrder(string ordername, unordered_map<string, set<string>*> &orderMap, vector<Order> &orderlist)
{
//	cout << "Begin to place ordername : " + ordername << endl;
	set<string> *dep = orderMap[ordername];

	if (dep != NULL) {
		for (set<string>::iterator setit = dep->begin(); setit != dep->end(); setit++) {
			string depname = *setit;
			bool dep_solved = bool();

			for (int order_index = 0; order_index < orderlist.size(); order_index++) {
				Order order = orderlist[order_index];
				if (order.ordername == depname) {
					dep_solved = true;
					break;
				}
			}
			if (!dep_solved) {
//				cout << "[Hold] in placing ordername : " + ordername << endl;
				return -1;
			}
		}
	} else {
//		cout << "[No Dep] in placing ordername : " + ordername << endl;
	}
	Order order = {ordername};
	orderlist.push_back(order);

	return 0;
}

vector<Order> OrderSort(const vector<Order> &orderlist, const vector<OrderDep> &orderDep)
{
	vector<Order> order_in_sort;
	vector<set<string> *> free_list;
	vector<Order> _orderlist = orderlist;
	unordered_map<string, set<string> *> orderMap;

	for (int order_dep_index = 0; order_dep_index < orderDep.size(); order_dep_index++) {
		OrderDep orderdep = orderDep[order_dep_index];
		string ordername = orderdep.order.ordername;
		string depname = orderdep.orderDep.ordername;

		// Check if at least one dependency exists for the order
		if (orderMap[ordername] == NULL) {
			orderMap[ordername] = new set<string>();
			free_list.push_back(orderMap[ordername]);
		}
		set<string> *set_order = orderMap[ordername];
		set_order->insert(depname);
	}

	while (!_orderlist.empty()) {
		for (int order_index = 0; order_index < _orderlist.size(); order_index++) {
			Order order = _orderlist[order_index];
			string ordername = order.ordername;

			if (0 == PlaceOrder(ordername, orderMap, order_in_sort)) {
				_orderlist.erase(_orderlist.begin() + order_index);
				order_index -= 1;
			}
		}
	}

	// Freeing before finishing
	for (int free_index = 0; free_index < free_list.size(); free_index++) {
		free(free_list[free_index]);
	}

	return order_in_sort;
}

void Print(vector<Order> &orderlist)
{
	for (int order_index = 0; order_index < orderlist.size(); order_index++) {
		cout << orderlist[order_index].ordername << endl;
	}
}

int main(int arch, char *argv[])
{
	vector<Order> orderlist;
	vector<OrderDep> orderDep;

	Order order_1 = {"firstorder"};
	Order order_2 = {"secondorder"};
	Order order_3 = {"thirdorder"};

	orderlist.push_back(order_1);
	orderlist.push_back(order_2);
	orderlist.push_back(order_3);

	OrderDep order_dep_1 = {order_1, order_2};
	OrderDep order_dep_2 = {order_2, order_3};

	orderDep.push_back(order_dep_1);
	orderDep.push_back(order_dep_2);

	vector<Order> result = OrderSort(orderlist, orderDep);

	Print(result);

	return 0;
}
