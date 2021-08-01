#!/usr/bin/python3

import argparse
import shutil
import subprocess
import os


SCRIPT_DIR = os.path.realpath(os.path.dirname(__file__))
WKSP_DIR = os.path.dirname(SCRIPT_DIR)
BUILD_DIR = os.path.join(WKSP_DIR, "build")


def log_error(msg):
    print("error: " + msg)


def log_info(msg):
    print("info: " + msg)


def log_warn(msg):
    print("warn: " + msg)


def log_debug(msg):
    print("debug: " + msg)


def build(args):
    log_info("start building")
    init_cmake_command = ["cmake", "-G", "Ninja", ".."]
    build_command = ["ninja"]
    if not os.path.exists(BUILD_DIR):
        os.mkdir(BUILD_DIR)
        if args.prefix:
            log_debug(args.prefix)
            init_cmake_command.append("-DCMAKE_INSTALL_PREFIX=" + args.prefix)
        ret = subprocess.Popen(init_cmake_command, cwd=BUILD_DIR)
        ret.wait()
        if ret.returncode != 0:
            log_error("cmake initialize failed")
    ret = subprocess.Popen(build_command, cwd=BUILD_DIR)
    ret.wait()
    if ret.returncode != 0:
        log_error("build failed")
        return
    log_info("build success")


def install(args):
    log_info("start installing")
    install_command = ["ninja", "install"]
    if not os.path.exists(BUILD_DIR):
        log_error("not found `build` director, nothing to do")
        return

    ret = subprocess.Popen(install_command, cwd=BUILD_DIR)
    ret.wait()
    if ret.returncode != 0:
        log_error("install failed")
        return

    log_info("install success")


def clean(args):
    log_info("start cleaning")
    if not os.path.exists(BUILD_DIR):
        log_warn("no `build` directory exists, nothing to do")
        return

    shutil.rmtree(BUILD_DIR, ignore_errors=True)
    log_info("clean success")


def main():
    parser = argparse.ArgumentParser(description = 'build project')
    subparsers = parser.add_subparsers(help = 'sub command help')
    cmd_build_parser = subparsers.add_parser('build', help = 'build project')
    cmd_build_parser.add_argument('--prefix', help='specify the install destination directory')
    cmd_build_parser.set_defaults(func = build)
    cmd_install_parser = subparsers.add_parser('install', help = 'install products')
    cmd_install_parser.set_defaults(func = install)
    cmd_clean_parser = subparsers.add_parser('clean', help = 'clean project')
    cmd_clean_parser.set_defaults(func = clean)

    args = parser.parse_args()
    args.func(args)


if __name__ == '__main__':
    main()
