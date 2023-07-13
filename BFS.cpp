#include <iostream>
#include <list>
#include <string>

// struct of node
class Node
{
public:
	std::string name;
	std::list<Node> friends;
	Node(const std::string name, std::list<Object> friends) : name(name), friends(friends) {};
	Node(const std::string name) : name(name) {};

};

std::string BFS(std::list<Object>& queue, std::string findName)
{
	while (queue.size() != 0) {
		if (queue.front().name != findName) {
			for (auto& var : queue.front().friends)
				queue.push_back(var);
			queue.pop_front();
		}
		else
			return queue.front().name;
	}
	return "Not found";
}

int main()
{
  // create graph using our node - class Object
	Node node1("People_1", std::list<Node> {Node("People_4"), Node("People_7"), Node("People_10")});
	Node node2("People_2", std::list<Node> {Node("People_5"), Node("People_8"), Node("People_11")});
	Node node3("People_3", std::list<Node> {Node("People_6"), Node("People_9"), Node("People_12")});
  // create main node to link graph's branches
	Node node("Me", std::list<Node> {Node(node1.name, node1.friends), Node(node2.name, node2.friends), Node(node3.name, node3.friends)});

	std::list<Node> queue;
	std::string findName = "Kevin";

	queue.push_back(node);
	std::cout << BFS(queue, findName) << std::endl;


	return 0;
}
