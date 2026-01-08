#include "display_tree.h"
#include "dynamic.h"
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

    DYNAMIC_APPEND(MatchNode*, file_node->match_nodes, file_node->match_count, file_node->match_capacity, match_node);
}

DirectoryNode* directory_node_new(const char* dirname) {
    DirectoryNode* new_directory_node = malloc(sizeof(DirectoryNode));

    if (new_directory_node == 0)
        exit(1);

    new_directory_node->dir_name = dirname;
    new_directory_node->match_count = 0;

    new_directory_node->child_dir_capacity = 0;
    new_directory_node->child_dir_count = 0;

    new_directory_node->child_file_capacity = 0;
    new_directory_node->child_file_count = 0;

    return new_directory_node;
}

void directory_node_add_file_node(DirectoryNode* dn, FileNode* fn) {
    assert(dn != 0);
    assert(fn != 0);

    DYNAMIC_APPEND(FileNode*, dn->child_files, dn->child_file_count, dn->child_file_capacity, fn);
}

void directory_node_add_directory_node(DirectoryNode* dnroot, DirectoryNode* dnchild) {
    assert(dnroot != 0);
    assert(dnchild != 0);

    DYNAMIC_APPEND(DirectoryNode*, dnroot->child_dirs, dnroot->child_dir_count, dnroot->child_dir_capacity, dnchild);
}
