const std = @import("std");
const build = @import("builtin");
const os = build.os.tag;


pub fn main() !void {
    std.debug.print("The os is {}", .{os});
}