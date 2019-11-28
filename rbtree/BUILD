
package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "rbtree",
    srcs = ["rbtree.cc"],
    hdrs = ["rbtree.h"],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [":rbtree"],
)
