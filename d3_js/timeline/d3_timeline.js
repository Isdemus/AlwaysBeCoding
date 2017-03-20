(function() {
	'use strict';

	console.log("What's wrong");

	var CONFIG = {
		maxBubbleRadius: 20,
		dateDomainPadding: 5, // years
		kincaidDomainPadding: .1,
		xAxisLabel: 'Year',
		yAxisLabel: 'Positive Score',
		keyCircleLabel: 'Number of words',
		noneSelectedOpacity: .3,
		selectedOpacity: 1,
		unselectedOpacity: .07,
		row_cells: 4,
		headingText: 'Timeline of isdemus'
	};

	var presidents, speeches, selectedSpeech, points;

	var margin = {top: 10, right: 10, bottom: 50, left: 50};

	var width = 940 - margin.left - margin.right,
		height = 400 - margin.top - margin.bottom;

	var gia = d3.select('#gia-sotu');

	gia.append('h1')
		.attr('id', 'timeline_title')
		.text(CONFIG.headingText);

	var chartContainer = gia.append('div');

	var chart = chartContainer.append('div')
					.attr('id', 'gia-sotu-chart');

	var svg = chart.append('svg')
			.attr('width', width + margin.left + margin.right)
			.attr('height', height + margin.top + margin.bottom);

	// chartContainer
	// 	.style('height', chart.node().offsetHeight + 'px');

	svg = svg.append('g')
			.attr('transform', 'translate(' + margin.left + ',' + margin.top + ')');

	var background = svg.append('rect')
			.attr('x', 0)
			.attr('y', 0)
			.attr('width', width  )
			.attr('height', height)
			.style('fill', '#fff' )
			// .on('mouseout', function(e) { selectedSpeech = null; render(); })
			// .on('mousemove', function() { selectByX(d3.mouse(this)[0]) })
			// .on('click', scrollToSelected);

// 	var elPopup = chart.append('div')
// 					.attr('id', 'gia-sotu-popup');

// 	var elPresidents = gia.append('div').attr('id', 'gia-sotu-presidents');

// 	var presidentTemplate = _.template(d3.select('#gia-sotu-presidentTemplate').html());
// 	var popupTemplate = _.template(d3.select('#gia-sotu-popupTemplate').html());

	var yyyymmdd = d3.time.format('%Y-%m-%d');
	var formatDate = d3.time.format('%-d %B %Y');
	var formatKincaid = d3.format('.1f');

// 	function portraitUrl(name) {
// 		return host() + 'img/portraits/' + name.toLowerCase().replace(/[\s.]+/g, '-') + '.jpg';
// 	}

// 	function portraitTag(name) {
// 		return '<img src="' + portraitUrl(name) + '" alt="' + name + '">';
// 	}

// 	var helpers = {
// 		addCommas: d3.format(','),
// 		portraitUrl: portraitUrl,
// 		portraitTag: portraitTag,
// 		formatDate : formatDate,
// 		formatKincaid: formatKincaid
// 	};


	/*
	 ********************
	 Scaler definitions
	 ********************
	 */

	 console.log("width : " + width);
	var xScale = d3.time.scale()
			.domain([1992 + 1, 2018 - 1])
			.range([0, width]);

	var yScale = d3.scale.linear()
			.domain([-99, 99])
			.range([height, 0]);

	var colors = d3.scale.category10();

	var wordCountScale = d3.scale.sqrt()
							.range([0, CONFIG.maxBubbleRadius]);

	var xAxis = d3.svg.axis()
					.scale(xScale)
					.tickFormat(d3.format("f"))
					.orient('bottom');

	var yAxis = d3.svg.axis()
					.scale(yScale)
					.orient('left');

// 	var keyCircle = scaleKeyCircle()
// 					.scale(wordCountScale)
// 					.tickValues([3000, 30000]);

	svg.append('g')
		.attr('class', 'x axis')
		.attr('transform', 'translate(0, ' + height + ')')
		.append('text')
			.attr('transform', 'translate(' + (width / 2) + ', 0)')
			.attr('class', 'gia-axisLabel')
			.attr('x', 0)
			.attr('y', 40)
			.style('text-anchor', 'middle')
			.text(CONFIG.xAxisLabel);

	svg.append('g')
		.attr('class', 'y axis')
		.append('text')
			.attr('class', 'gia-axisLabel')
			.attr('transform', 'rotate(90) translate(' + (height / 2) + ' 0)')
			.attr('x', 0)
			.attr('y', 40)
			.style('text-anchor', 'middle')
			.text(CONFIG.yAxisLabel);

	var popupConnectors = svg.append('g')
							.attr('id', 'popupConnectors');

	popupConnectors.append('line').attr('class', 'connector1');
	popupConnectors.append('line').attr('class', 'connector2');

	svg.append('g')
		.attr('class', 'speeches');

	function renderAxis() {
		svg.select('g.x.axis')
			.call(xAxis);

		svg.select('g.y.axis')
			.call(yAxis);
	}
	renderAxis();

// 	function renderAnnotations() {
// 		chart.append('div')
// 			.attr('class', 'gia-sotu-annotation')
// 			.html('<b>2 December 1823</b><br>James Monroe delivers an address that would later become<br> known as the Monroe Doctrine, a key tenet of US foreign<br> policy for almost two centuries')
// 			.style('top', margin.top + 'px')
// 			.style('left', margin.left + 137 + 'px')
// 			.append('div')
// 				.attr('class', 'gia-sotu-annotation-line')
// 				.style('height', '75px')


// 		chart.append('div')
// 			.attr('class', 'gia-sotu-annotation')
// 			.html("<b>2 December 1913</b><br>Woodrow Wilson’s speech follows more than<br> 100 years of the address being delivered to<br> Congress as a written submission. His precedent<br> is (mostly) followed to this day")
// 			.style('top', margin.top + 'px')
// 			.style('left', margin.left + 510 + 'px')
// 			.append('div')
// 				.attr('class', 'gia-sotu-annotation-line')
// 				.style('height', '70px')
// 	}

	function renderPoints() {
		var g = svg.select('g.speeches');

		points = g.selectAll('circle.speech')
					.data(speeches);

		points.enter()
			.append('circle')
			.attr('class', 'speech')
			.attr('cx', function(d) { return xScale(d.date) })
			.attr('cy', function(d) { return yScale(d.kincaid) })
			.attr('r', function(d) { return wordCountScale(d.wc) })
			.attr('fill', function(d) { return colors(d.president.name) })
			// .attr('stroke', function(d) { return d.oral ? '#999' : '#966' })
			.attr('stroke', 'rgba(0,0,0, .05)')
			// .attr('stroke-dasharray', function(d) { return d.oral ? '1, 1' : '1' })
			.on('mouseover', function(d) { selectedSpeech = d; render(); })
			.on('click', scrollToSelected);

		points
			.classed('selected', function(d) { return selectedSpeech && d === selectedSpeech })
			.attr('fill-opacity', function(d) {
				if (selectedSpeech) {
					return d === selectedSpeech ? CONFIG.selectedOpacity : CONFIG.unselectedOpacity;
				} else {
					return CONFIG.noneSelectedOpacity;
				}
			});
	}
})();