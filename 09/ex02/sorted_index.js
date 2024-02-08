const numbers = []

process.argv.forEach(function (val, index, array) {
    // console.log(index + ': ' + val);
    numbers.push(val);
});

const initial = [...numbers.slice(2)]

const sorted = {}
numbers.slice(2).sort().map((value, index) => {
    // console.log(index + ': ' + value);
    sorted[value] = index;
});

initial.forEach((val) => {
    console.log(val + ': ' + sorted[val]);
})