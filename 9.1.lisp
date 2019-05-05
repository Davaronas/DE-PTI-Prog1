(defun factorial (n)
  (if (= n 0)
      1
      (* n (factorial (- n 1))) ) )

(defun fact (n)
    (do
       ((i 1 (+ 1 i))
        (prod 1 (* i prod)))
       ((equal i (+ n 1)) prod)))
