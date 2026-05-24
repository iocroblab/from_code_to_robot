// docs/javascripts/katex-init.js
document$.subscribe(() => {
  renderMathInElement(document.body, {
    // Support both $...$ (inline) and $$...$$ (display)
    delimiters: [
      { left: "$$", right: "$$", display: true },
      { left: "$",  right: "$",  display: false },
      { left: "\\(", right: "\\)", display: false },
      { left: "\\[", right: "\\]", display: true }
    ],
    throwOnError: false
  });
});
