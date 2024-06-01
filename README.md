# 🚀 superoptimizer
A superoptimizer implementation for a *not-so fictive* programming language called [AG2 lang](./ag2-lang/).

## Overview

What's the idea? Really simple: optimize a *-for now deterministic-* program. A superoptimizer uses compiler theory algorithms to determine the best program that replicates the same output as the given program.

If you want to learn more about the subject, here are a couple of sources:
* [Superoptimization - Wikipedia](https://en.wikipedia.org/wiki/Superoptimization)
* [Dead-code elimination (compiler theory) - Wikipedia](https://en.wikipedia.org/wiki/Dead-code_elimination)
* [Peephole optimization (compiler theory) - Wikipedia](https://en.wikipedia.org/wiki/Peephole_optimization)

## Examples

This program:
```js
LOAD 77
SWAP 0 1
LOAD 8
XOR 0 1
SWAP 0 1
LOAD 0
SWAP 0 1
```
Is *superoptimized* as:
```js
LOAD 69
```
Test the two using the `ag2` compiler, I'm not lying! They have the exact same output.
