function showSection(sectionId) {
  // Hide all sections
  const sections = document.querySelectorAll(".file-section");
  sections.forEach((section) => {
    section.classList.remove("active");
  });

  // Remove active class from all buttons
  const buttons = document.querySelectorAll(".nav-btn");
  buttons.forEach((btn) => {
    btn.classList.remove("active");
  });

  // Show selected section
  document.getElementById(sectionId).classList.add("active");

  // Activate clicked button
  event.target.classList.add("active");

  // Scroll to top
  window.scrollTo({ top: 0, behavior: "smooth" });
}
