function cmp(a, b)
{
	return a > b;
}

var computeArea = function(A, B, C, D, E, F, G, H) 
{
	var tot = (C-A) * (D-B) + (G-E) * (H-F);
	var overlap = 0;

	if (C<=E || A>=G || D<=F || B>=H)
	{
		overlap = 0;
	} else if (A>=E && B>=F && C<=G && D<=H)
	{
		overlap = (C-A) * (D-B); 
	} else if (A<=E && B<=F && C>=G && D>=H)
	{
		overlap = (G-E) * (H-F);
	} else 
	{
 		var x = [A, C, E, G].sort(cmp);
    	var y = [B, D, F, H].sort(cmp);
   		overlap = (y[2]-y[1]) * (x[2]-x[1]);
	}

	return tot - overlap;
};