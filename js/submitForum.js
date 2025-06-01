document.addEventListener("DOMContentLoaded", function() {
    console.log("DOM fully loaded and parsed");
    
    const form = document.getElementById("submissionForm");
    
    if (!form) {
        console.log("Form not found!");
        return;
    }
    
    console.log("Form found, attaching submit event listener");
    
    form.addEventListener("submit", function(event) {
        console.log("Form submitted");
        event.preventDefault();
        
        const formData = new FormData(form);
        
        for (let [key, value] of formData.entries()) {
            console.log(key + "=" + value);
        }
    });
});
