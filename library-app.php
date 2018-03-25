<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<!--
	Created by: Gabriel Cabrera
				Kevin Buranasombati
				Jaime Arnold
				Ian Martin
				Tyrone Moore
				
	url: nrs-projects.humboldt.edu/~gjc129/library-app/library-app.php
	
-->

<head>
	<title> Library book finder</title>

    <meta charset="utf-8" />
    
    <link href="library-app.css" type="text/css" rel="stylesheet" />
   	
   	

</head>

<body>

<?php 
	if(! array_key_exists("title", $_GET))
	{
		?>
		<form method="get" action="<?=htmlentities($_SERVER['PHP_SELF'], ENT_QUOTES) ?>">

		<h1>Welcome to the Library Book Finder</h1>
		<h2>Helping books not feel lonely, one search at-a-time.</h2>
		<hr />

		<fieldset>
		<legend>Please enter a book title to search: </legend>
		<label> Title: <input type="text" name="title" /></label>
		<br />

		<div class="submit"> 
		<input type="submit" />
		</div>

		</fieldset>
		
		</form>

		<?php	
	}
	
	else
	{
		?>
		<form method="get" action="<?=htmlentities($_SERVER['PHP_SELF'], ENT_QUOTES) ?>">
		
		<h1>Welcome to the Library Book Finder</h1>
		<h2>Helping books not feel lonely, one search at-a-time.</h2>
		<hr />
		
		<fieldset>
		<legend>Please enter a book title to search: </legend>
		<label> Title: <input type="text" name="title" /></label>
		<br />

		<div class="submit"> 
		<input type="submit" />
		</div>

		</fieldset>
		
		<p> Book's location is in vicinity of red circle. </p>		 
		<div class="image">
		
		<?php 
            if($_GET['title'] == "ac")
            {
            ?>
				<h1 style="margin-left: -13.5em; margin-top: 3em; color: red;">o</h1>
            <?php
            } 
            elseif ($_GET['title'] == "bl") 
            {
            ?>
                <h1 style="margin-left: -14em; margin-top: 6.5em; color: red;">o</h1>

            <?php
            }
            elseif($_GET['title'] == "ds") 
            {
            ?>
                <h1 style="margin-left: -18.5em; margin-top: 13.5em; color: red;">o</h1>

            <?php
            }
            
            elseif($_GET['title'] == "ha") 
            {
            ?>
                <h1 style="margin-left: -19.5em; margin-top: 3.5em; color: red;">o</h1>
                
			<?php
			}
            elseif($_GET['title'] == "hg") 
            {
            ?>
                <h1 style="margin-left: -23em; margin-top: 6.5em; color: red;">o</h1>
			<?php
			}
            elseif($_GET['title'] == "nx")
            {
            ?>
                <h1 style="margin-left: -23em; margin-top: 13.3em; color: Red;">o</h1>
            <?php
            }
        ?>
			<!-- <h1 style="margin-left: -23em; margin-top: 13.3em;">o</h1> -->
				
		</div>
		</form>
		<?php
	}	
		?>

</body>
</html>