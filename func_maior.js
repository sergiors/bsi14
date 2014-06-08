#!/usr/bin/env node

var maior = function(n1, n2) {
	if (n1 > n2) {
		return n1;
		// return true;
	}

	return n2;
	// return false;
}

var maior3 = function(n1,n2,n3) {
	// if (maior(n1, n2) && maior(n1, n3)) {
	// 	return n1;
	// }

	// if (maior(n2, n1) && maior(n2, n3)) {
	// 	return n2;
	// }

	// return n3;

	return maior(n1, maior(n2, n3));
}

console.log(maior3(43, 2222, 1111));

