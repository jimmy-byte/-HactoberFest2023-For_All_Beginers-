// Kotlin program to find the list of numbers palindrome within a range

// Function to check if a number is palindrome or not
private fun isPalindromeNumber(n: Int): Boolean {
    return n.toString() == n.toString().reversed()
}

// Function to find the list of palindrome numbers within a range
fun palindromeNumbersWithinARange(start: Int, end: Int): List<Int> {
    val palindromes = mutableListOf<Int>()
    for (i in start..end) {
        if (isPalindromeNumber(i)) {
            palindromes.add(i)
        }
    }
    return palindromes
}