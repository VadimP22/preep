#include "display_tree.h"
#include "stdlib.h"
#include "assert.h"
#include "memory.h"

MatchNode* match_node_new(const char* content, int line_number, bool is_fragment) {
    assert(content != 0);

    MatchNode* match_node = malloc(sizeof(MatchNode));

    if (match_node == 0) {
        exit(1);
    }

    match_node->raw_text = content;
    match_node->is_fragment = is_fragment;
    match_node->line_number = line_number;

    return match_node;
}

FileNode* file_node_new(const char* filename) {
    assert(filename != 0);

    FileNode* file_node = malloc(sizeof(FileNode));

    if (file_node == 0)
        exit(1);

    file_node->filename = filename;
    file_node->match_count = 0;
    file_node->match_capacity = 0;

    return file_node;
}

void file_node_add_match_node(FileNode* file_node, MatchNode* match_node) {
    assert(file_node != 0);
    assert(match_node != 0);

    file_node->match_count += 1;

    if (file_node->match_capacity < file_node->match_count) {
        int old_capacity = file_node->match_capacity;

        if  (file_node->match_capacity == 0) {
            file_node->match_capacity = 1;
        } else {
            file_node->match_capacity *= 2;
        }

        MatchNode** new_match_nodes = malloc(sizeof(*new_match_nodes) * file_node->match_capacity);

        assert(new_match_nodes != 0);

        if (old_capacity != 0) {
            assert(file_node->match_nodes != 0);
            memcpy(new_match_nodes, file_node->match_nodes, sizeof(MatchNode*) * old_capacity);
        }

        file_node->match_nodes = new_match_nodes;
    }

    file_node->match_nodes[file_node->match_count - 1] = match_node;
}