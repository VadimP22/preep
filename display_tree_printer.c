#include "display_tree_printer.h"

#include "stdio.h"

void match_node_print(MatchNode *self) {
    printf("%d:", self->line_number);  

    if (self->is_fragment) {
        printf(" ... %s ...", self->raw_text);
    } else {
        printf(" %s", self->raw_text);
    }
}

void file_node_print(FileNode* file_node) {
    printf("%s", file_node->filename);
}
