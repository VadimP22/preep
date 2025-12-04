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
    file_node->match_count += 1;

    if (file_node->match_capacity < file_node->match_count) {
        MatchNode* new_match_nodes[] = malloc(sizeof(MatchNode*) * file_node->match_count);
        // TODO: memcpy
    }
}