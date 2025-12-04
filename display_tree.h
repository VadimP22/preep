#pragma once

#include "stdbool.h"

typedef struct MatchNode {
    const char* raw_text;
    int line_number;
    bool is_fragment;
} MatchNode;

MatchNode* match_node_new(const char*, int, bool);


typedef struct FileNode {
    const char* filename;

    int match_capacity;
    int match_count;
    MatchNode* match_nodes[];
} FileNode;

FileNode* file_node_new(const char*);
void file_node_add_match_node(FileNode*, MatchNode*);


typedef struct DirectoryNode {
    const char* dir_name;
    int match_count;

    int child_dir_capacity;
    int child_dir_count;
    struct DirectoryNode** child_dirs;

    int child_file_capacity;
    int child_file_count;
    FileNode* child_files[];
} DirectoryNode;

DirectoryNode* directory_node_new(const char*);
