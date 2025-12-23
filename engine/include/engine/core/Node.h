//
// Created by bytenol on 12/23/25.
//

#ifndef ZEPHYRUS_NODE_H
#define ZEPHYRUS_NODE_H

#include <vector>
#include <string>

namespace zpy {

    class Node {
    public:
        std::string name;
        std::vector<Node> children;
        explicit Node(const std::string &n="Node"): name(n) {};
        void AddChild(const Node& child);
    };

}

#endif //ZEPHYRUS_NODE_H