window.addEventListener("load", function () {
  const carousels = document.querySelectorAll(".glider");
  Object.keys(carousels).map(function (i) {
    const carousel = carousels[i];
    const prevButton = carousel.parentElement.getElementsByClassName(
      "carousel-previous-button"
    )[0];
    const nextButton = carousel.parentElement.getElementsByClassName(
      "carousel-next-button"
    )[0];
    const dots = carousel.parentElement.getElementsByClassName("dots")[0];

    /*
    smallest (mobile/default): 1 col
    mobile large: 1 col >= 480
    tablet: 3 col >= 640
    desktop: 4 col >= 1024
  */

    let options = {
      // Mobile-first defaults
      scrollLock: true,
      arrows: {},
      responsive: [],
    };

    let responsive480 = {
      // screens greater than >= 480px
      breakpoint: 480,
      settings: {
        // Set to `auto` and provide item width to adjust to viewport
        slidesToShow: "1",
        slidesToScroll: "1",
      },
    };

    let responsive640 = {
      // screens greater than >= 640px
      breakpoint: 640,
      settings: {
        // Set to `auto` and provide item width to adjust to viewport
        slidesToShow:
          (carousel.dataset.slidesToShow || "1") > "2"
            ? "2"
            : carousel.dataset.slidesToShow || "1",
        slidesToScroll:
          (carousel.dataset.slidesToShow || "1") > "2"
            ? "2"
            : carousel.dataset.slidesToShow || "1",
        arrows: {},
      },
    };

    if (!!dots) {
      options.dots = dots;
      responsive480.settings.dots = dots;
    }

    let responsive1024 = {
      // screens greater than >= 1024px
      breakpoint: 1024,
      settings: {
        // Set to `auto` and provide item width to adjust to viewport
        slidesToShow:
          (carousel.dataset.slidesToShow || "1") > "3"
            ? "3"
            : carousel.dataset.slidesToShow || "1",
        slidesToScroll:
          (carousel.dataset.slidesToShow || "1") > "3"
            ? "3"
            : carousel.dataset.slidesToShow || "1",
        arrows: {},
      },
    };

    let responsive1280 = {
      // screens greater than >= 1024px
      breakpoint: 1280,
      settings: {
        // Set to `auto` and provide item width to adjust to viewport
        slidesToShow: carousel.dataset.slidesToShow || "1",
        slidesToScroll: carousel.dataset.slidesToShow || "1",
        arrows: {},
      },
    };

    if (!!carousel.dataset.itemWidth) {
      responsive640.settings.itemWidth = carousel.dataset.itemWidth;
      responsive1024.settings.itemWidth = carousel.dataset.itemWidth;
      responsive1280.settings.itemWidth = carousel.dataset.itemWidth;
    }

    if (!!prevButton) {
      responsive640.settings.arrows.prev = prevButton;
      responsive1024.settings.arrows.prev = prevButton;
      responsive1280.settings.arrows.prev = prevButton;
    }

    if (!!nextButton) {
      responsive640.settings.arrows.next = nextButton;
      responsive1024.settings.arrows.next = nextButton;
      responsive1280.settings.arrows.next = nextButton;
    }

    options.responsive.push(
      responsive480,
      responsive640,
      responsive1024,
      responsive1280
    );

    const glider = new Glider(carousel, options);
    // assign to self to property access methods
    glider.ele.Glider = glider;
  });

  // re-calculate for carousels when tabs are clicked
  const tabs = document.querySelectorAll(
    "#main-content .usa-accordion__button"
  );
  Object.keys(tabs).map(function (tab) {
    tabs[tab].onclick = function (e) {
      const containerId = e.target.attributes.getNamedItem("aria-controls")
        .value;
      const carousels = document
        .getElementById(containerId)
        .querySelectorAll(".glider");
      const count = carousels.length;

      let resize = function (i) {
        // foreach nested carousel, resize
        setTimeout(function () {
          if (!!carousels[i]) {
            carousels[i].Glider.resize();
          }
        }, 0);
      };

      for (let i = 0; i <= count; i++) {
        resize(i);
      }
    };
  });
});
