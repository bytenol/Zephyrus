#include "../include/engine/core/Node.h"

void zpy::Node::AddChild(const Node &child) {
    children.push_back(child);
}
