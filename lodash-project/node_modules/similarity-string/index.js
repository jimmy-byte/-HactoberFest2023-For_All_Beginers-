String.prototype.replaceAll = function (search, replacement) {
    return this.replace(new RegExp(search, 'g'), replacement);
};

function appear_times(value, base) {
    return (base.length - base.replaceAll(value, "").length) / value.length
}

function similarity(value, base, initial_set_size = 4) {
    let rel = 0;
    for (let _i = initial_set_size; _i <= value.length; _i++) for (let _s = 0; _s < value.length; _s++) if (_s + _i <= value.length)
        rel += appear_times(value.substring(_s, _s + _i), base);
    return rel - Math.abs(base.length - value.length)
}

module.exports = function (a, b, initial_set_size = 2) {
    let value = a.length < b.length ? a : b;
    let base = a.length < b.length ? b : a;
    let full_rel = similarity(base, base, initial_set_size);
    let real_rel = similarity(value, base, initial_set_size);
    if (real_rel <= 0) return 0;
    return (real_rel / full_rel) * 100
};