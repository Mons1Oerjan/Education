/**
 * Function that validates that the password is equal to
 * the password confirmation field. If they are not equal,
 * then the submit button is disabled.
 */
function confirmPassword() {
    var passwordConfirmationField = document.getElementById('password_confirmation');
    var passwordField = document.getElementById('password');
    var submitButton = document.getElementById('submit');

    if (passwordField !== passwordConfirmationField) {
        submitButton.disabled = true;
    }

    submitButton.disabled = false;
}
