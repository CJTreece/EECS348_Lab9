<!DOCTYPE html>
<html>
<head>
	<title>Carson Treece Multiplication Table</title>
</head>
<body>
	<?php
        if (isset($_POST['submit'])) {
            $number = $_POST['number'];
            echo "<table border='1'>";
            for ($i = 0; $i <= $number; $i++) {
                echo "<tr>";
                for ($j = 0; $j <= $number; $j++) {
                    if ($i == 0 && $j == 0) {
                        echo "<td></td>";
                    } else if ($i == 0) {
                        echo "<td><b>$j</b></td>";
                    } else if ($j == 0) {
                        echo "<td><b>$i</b></td>";
                    } else {
                        echo "<td>" . $i * $j . "</td>";
                    }
                }
                echo "</tr>";
            }
            echo "</table>";
        }
	?>
</body>
</html>