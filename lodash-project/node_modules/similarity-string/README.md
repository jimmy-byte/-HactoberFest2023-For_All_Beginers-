
# similarity-string 

[![npm version][npm-badge]][npm]
[![Build Status][travis-badge]][travis]
[![Dependency Status][david-badge]][david]
[![DevDependency Status][david-badge-dev]][david-dev]

similarity-string compares strings **focusing on common char sets**. 
```bash
npm install similarity-string --save
```
Implement it:
```node
String.similarity = require("similarity-string");
let percent = String.similarity("xummy", "dummy");
```
### Reason
I recently tested the Levenshtein distance for matching poblation names with a given value and I notice it wasn't enought.

> The Levenshtein distance is a string metric for measuring the difference between two sequences ([Wikipedia](https://en.wikipedia.org/wiki/Levenshtein_distance))

Comparing a value with a set of names the Levenshtein distance returned the same distance for multiple names.
I got better results by comparing common char sequences:
```
xummy - dummy: 60.00% [░░░░░░░░░░░░░░░          ] (leven: 1)
dxmmy - dummy: 30.00% [░░░░░░░░                 ] (leven: 1)
```
### Test
Clone the repository and run:
```bash
npm install
npm test
```

```
xummy - dummy: 60.00% [░░░░░░░░░░░░░░░          ] 
dxmmy - dummy: 30.00% [░░░░░░░░                 ] 
duxmy - dummy: 20.00% [░░░░░                    ] 
dumxy - dummy: 30.00% [░░░░░░░░                 ] 
dummx - dummy: 60.00% [░░░░░░░░░░░░░░░          ] 
xumming - dumming: 71.43% [░░░░░░░░░░░░░░░░░░       ] 
dxmming - dumming: 47.62% [░░░░░░░░░░░░             ] 
duxming - dumming: 33.33% [░░░░░░░░                 ] 
dumxing - dumming: 28.57% [░░░░░░░                  ] 
dummxng - dumming: 33.33% [░░░░░░░░                 ] 
dummixg - dumming: 47.62% [░░░░░░░░░░░░             ] 
dumminx - dumming: 71.43% [░░░░░░░░░░░░░░░░░░       ] 
```
#### Levenshtein comparision
```
xummy - dummy: 80.00% [░░░░░░░░░░░░░░░░░░░░     ] 
dxmmy - dummy: 80.00% [░░░░░░░░░░░░░░░░░░░░     ] 
duxmy - dummy: 80.00% [░░░░░░░░░░░░░░░░░░░░     ] 
dumxy - dummy: 80.00% [░░░░░░░░░░░░░░░░░░░░     ] 
dummx - dummy: 80.00% [░░░░░░░░░░░░░░░░░░░░     ] 
xumming - dumming: 85.71% [░░░░░░░░░░░░░░░░░░░░░    ] 
dxmming - dumming: 85.71% [░░░░░░░░░░░░░░░░░░░░░    ] 
duxming - dumming: 85.71% [░░░░░░░░░░░░░░░░░░░░░    ] 
dumxing - dumming: 85.71% [░░░░░░░░░░░░░░░░░░░░░    ] 
dummxng - dumming: 85.71% [░░░░░░░░░░░░░░░░░░░░░    ] 
dummixg - dumming: 85.71% [░░░░░░░░░░░░░░░░░░░░░    ] 
dumminx - dumming: 85.71% [░░░░░░░░░░░░░░░░░░░░░    ] 
``` 

[david]: https://david-dm.org/efraespada/similarity-string
[david-badge]: https://david-dm.org/efraespada/similarity-string.svg
[travis]: https://travis-ci.org/efraespada/similarity-string
[travis-badge]: https://travis-ci.org/efraespada/similarity-string.svg?branch=master
[david-dev]: https://david-dm.org/efraespada/similarity-string?type=dev
[david-badge-dev]: https://david-dm.org/efraespada/similarity-string/dev-status.svg
[npm]: https://www.npmjs.com/package/similarity-string
[npm-badge]: https://badge.fury.io/js/similarity-string.svg
