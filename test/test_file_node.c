#include "display_tree.h"

#include "stdio.h"
#include "assert.h"


void test_file_node_add_match_node() {
    MatchNode* mn1 = match_node_new("oferqjfw", 123, false);
    MatchNode* mn2 = match_node_new("oferqjfw", 124, true);
    MatchNode* mn3 = match_node_new("oferqjfw", 125, false);
    FileNode* fn1 = file_node_new("filenote1.txt");

    file_node_add_match_node(fn1, mn1);
    file_node_add_match_node(fn1, mn2);
    file_node_add_match_node(fn1, mn3);

    assert(fn1->match_nodes[0]->line_number == 123);
    assert(fn1->match_nodes[1]->line_number == 124);
    assert(fn1->match_nodes[2]->line_number == 125);
}

void test_directory_node_add_file_node() {
    DirectoryNode* dn = directory_node_new("name");
    FileNode* fn1 = file_node_new("1");
    FileNode* fn2 = file_node_new("2");
    FileNode* fn3 = file_node_new("3");

    directory_node_add_file_node(dn, fn1);
    directory_node_add_file_node(dn, fn2);
    directory_node_add_file_node(dn, fn3);

    assert(dn->child_files[0]->filename[0] == '1');
    assert(dn->child_files[1]->filename[0] == '2');
    assert(dn->child_files[2]->filename[0] == '3');
}

int main() {
    test_file_node_add_match_node();
    test_directory_node_add_file_node();
    return 0;
}
